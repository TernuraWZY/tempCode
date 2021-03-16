#include <iostream>
using namespace std;
// 基类 衣服
class Clothe
{
public:
    virtual void Show() = 0;
    virtual ~Clothe() {}
};

// 耐克衣服
class NiKeClothe : public Clothe
{
public:
    void Show()
    {
        std::cout << "我是耐克衣服，时尚我最在行！" << std::endl;
    }
};

// 基类 鞋子
class Shoes
{
public:
    virtual void Show() = 0;
    virtual ~Shoes() {}
};

// 耐克鞋子
class NiKeShoes : public Shoes
{
public:
    void Show()
    {
        std::cout << "我是耐克球鞋，让你酷起来！" << std::endl;
    }
};

class abstractFactory{
public:
    virtual Shoes *createShoes() = 0;
    virtual Clothe *createClothe() = 0;
    virtual ~abstractFactory() {};
};

class NIKEFactory : public abstractFactory{
public:
    Shoes *createShoes()
    {
        return new NiKeShoes();
    }
    Clothe *createClothe()
    {
        return new NiKeClothe();
    }
};