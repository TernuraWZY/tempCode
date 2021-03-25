#include <iostream>
using namespace std;

class constructor{

public:
    int &m_a;
    const int m_b;

public:
    // 初始化参数列表相当于调用拷贝构造函数，对于引用及const类型都需要参数化列表初始化
    // 构造函数内部则是使用赋值方法初始化
    constructor(int a, int b) : m_a(a), m_b(b) {}

    void display()
    {
        cout << "m_a is " << m_a 
             << "\nm_b is " << m_b << endl;
    }
};

int main()
{
    constructor obj(1, 2);
    obj.display();
}