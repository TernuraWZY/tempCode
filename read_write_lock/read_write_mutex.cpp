// 引入读写锁头文件
#include "read_write_mutex.h"

// 定义读写锁
zone::read_write_mutex rwmutex;

void read_function() {
    // 对该读操作，加读锁
    zone::unique_read_lock<zone::read_write_mutex> lock( rwmutex );
    // 读操作
}

void write_function() {
    // 对该写操作，加写锁
    zone::unique_write_lock<zone::read_write_mutex> lock( rwmutex );
    // 写操作
}