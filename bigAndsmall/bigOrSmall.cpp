#include <iostream>
using namespace std;

union order
{
    int a;
    char b;
};

int main()
{
    order uni;
    uni.a = 1;
    if(uni.b == 1)
        cout << "小端存储";
    else
        cout << "大端存储";
}