#include <iostream>
using namespace std;

class shoes{
public:
    virtual ~shoes() {}
    virtual void show() = 0;
};

class NIKEShoes : public shoes{
public:
    void show()
    {
        cout << "NIKE SHOES" << endl;
    }
};

class AdidasShoes : public shoes{
public:
    void show()
    {
        cout << "Adidas SHOES" << endl;
    }
};

class LiNingShoes : public shoes{
public:
    void show()
    {
        cout << "LiNing SHOES" << endl;
    }
};
// 抽象工厂
class AbstractShoesFactory{
public:
    // 根据鞋子型号选择鞋子对象类型
    virtual shoes *CreateShoes() = 0;
};

class NIKEShoesFactory : public AbstractShoesFactory{
public:
    shoes *CreateShoes()
    {
        return new NIKEShoes();
    }
};

class AdidasShoesFactory : public AbstractShoesFactory{
public:

    shoes *CreateShoes()
    {
        return new AdidasShoes();
    }
};

class LiNingShoesFactory : public AbstractShoesFactory{
public:
    shoes *CreateShoes()
    {
        return new LiNingShoes();
    }
};