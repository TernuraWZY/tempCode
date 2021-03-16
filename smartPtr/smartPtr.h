#include <iostream>

template <class T>
class smartPtr
{
private:
    class implement
    {
    public:
        implement(T *p) : m_p(p), count(1) {}
        ~implement() { delete m_p; }
        T *m_p;
        size_t count;
    };
    implement *m_implement;

public:
    explicit smartPtr(T *p) : m_implement(new implement(p)) {}
    ~smartPtr() { decrease(); }
    smartPtr(const smartPtr &other) : m_implement(other.m_implement)
    {
        increase();
    }
    smartPtr &operator=(const smartPtr &other)
    {
        // 避免自赋值
        if (m_implement != other.m_implement)
        {
            decrease();
            m_implement = other.m_implement;
            increase();
        }
        return *this;
    }
    T *operator->() const
    {
        return m_implement->m_p;
    }
    T &operator*() const
    {
        return *(m_implement->m_p);
    }

private:
    void decrease()
    {
        if (--(m_implement->count) == 0)
        {
            delete m_implement;
        }
    }
    void increase()
    {
        ++(m_implement->count);
    }
};
