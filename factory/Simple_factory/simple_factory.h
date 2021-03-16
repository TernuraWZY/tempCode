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

enum SHOES_TYPE
{
    NIKE,
    LINING,
    ADIDAS
};

class shoesFactory{
public:
    // 根据鞋子型号选择鞋子对象类型
    shoes *CreateShoes(SHOES_TYPE m_shoes)
    {
        switch (m_shoes)
        {
        case NIKE :
            return new NIKEShoes();
            break; 
        case ADIDAS :
            return new AdidasShoes();
            break;          
        case LINING :
            return new LiNingShoes();
            break;       
        default:
            return nullptr;
            break;
        }
    }
};