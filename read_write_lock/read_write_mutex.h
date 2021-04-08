// file: read_write_mutex.h
#pragma once

#include <mutex>
#include <condition_variable>
namespace zone
{
    class read_write_mutex
    {
    public:
        read_write_mutex() = default;
        ~read_write_mutex() = default;
        // 禁止拷贝构造、赋值
        read_write_mutex(const read_write_mutex &) = delete;
        read_write_mutex & operator=(const read_write_mutex &) = delete;

        read_write_mutex(const read_write_mutex &&) = delete;
        read_write_mutex & operator=(const read_write_mutex &&) = delete;

        void lock_read() {
            std::unique_lock<std::mutex> lock( m_mutex );
            // 第二种形式除了unique_lock<mutex>&参数外，第二个参数pred，即函数指针。当函数运行到该wait()函数时，
            // 若互斥量lck被锁定，且pred()返回值为false，则wait阻塞，必须同时满足，否则不会阻塞。其等同于下面的形式：
            // while (!pred()) wait(lck);
            // 当m_write_count != 0时表明写锁被占用，wait被阻塞
            m_cond_read.wait(lock, [this]()-> bool {
                    return m_write_count == 0;
                });
            
            ++m_read_count;
        }

        void unlock_read() {
            std::unique_lock<std::mutex> lock( m_mutex );
            // 读锁被释放时如果正在等待读锁线程为0且等待写锁线程不为0则唤醒等待写锁线程
            if (--m_read_count == 0 && m_write_count > 0) 
            {
                // 随机唤醒一个等待写条件变量的线程
                m_cond_write.notify_one();
            }
        }

        void lock_write() {
            std::unique_lock<std::mutex> lock( m_mutex );
            ++m_write_count;
            // 只有同时满足m_read_count == 0 && !m_writing这个wait才不会阻塞
            // 即正在等待读锁的线程为0且没有线程占用写锁
            m_cond_write.wait(lock, [this]()-> bool {
                    return m_read_count == 0 && !m_writing;
                });
            m_writing = true;
        }

        void unlock_write() {
            std::unique_lock<std::mutex> lock( m_mutex );
            if (--m_write_count == 0) {
                m_cond_read.notify_all();
            } else {
                m_cond_write.notify_one();
            }
            m_writing = false;
        }

    private:
        // 读等待数
        volatile size_t m_read_count = 0;
        // 写等待数
        volatile size_t m_write_count = 0;
        // 当前写锁是否被占
        volatile bool m_writing = false;
        std::mutex m_mutex;
        std::condition_variable m_cond_read;
        std::condition_variable m_cond_write;
    };



    template<typename _ReadWriteLock>
    class unique_read_lock
    {
    public:
        explicit unique_read_lock(_ReadWriteLock & rwLock)
            : m_ptr_rw_lock(&rwLock) {
            m_ptr_rw_lock->lock_read();
        }

        ~unique_read_lock() {
            if (m_ptr_rw_lock) {
                m_ptr_rw_lock->unlock_read();
            }
        }

        unique_read_lock() = delete;
        unique_read_lock(const unique_read_lock &) = delete;
        unique_read_lock & operator = (const unique_read_lock &) = delete;
        unique_read_lock(const unique_read_lock &&) = delete;
        unique_read_lock & operator = (const unique_read_lock &&) = delete;

    private:
        _ReadWriteLock * m_ptr_rw_lock = nullptr;
    };



    template<typename _ReadWriteLock>
    class unique_write_lock
    {
    public:
        explicit unique_write_lock(_ReadWriteLock & rwLock)
            : m_ptr_rw_lock(&rwLock) {
            m_ptr_rw_lock->lock_write();
        }

        ~unique_write_lock() {
            if (m_ptr_rw_lock) {
                m_ptr_rw_lock->unlock_write();
            }
        }

        unique_write_lock() = delete;
        unique_write_lock(const unique_write_lock &) = delete;
        unique_write_lock & operator = (const unique_write_lock &) = delete;
        unique_write_lock(const unique_write_lock &&) = delete;
        unique_write_lock & operator = (const unique_write_lock &&) = delete;

    private:
        _ReadWriteLock * m_ptr_rw_lock = nullptr;
    };
}