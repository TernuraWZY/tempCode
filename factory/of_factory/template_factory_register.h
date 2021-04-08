#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;

// 基类 鞋子
class Shoes
{
public:
    virtual void Show() = 0;
    virtual ~Shoes() {}

    static Shoes *New(const string &type)
    {
        if(shoesMap->find(type) == shoesMap->end())
        {
            cout << "unKnown type " << type << endl;
            return nullptr;
        }
        else
        {
            return (*shoesMap)[type]; 
        }
    }

    static void initMap()
    {
        static bool map_existed = false;
        if(!map_existed)
        {
            shoesMap = new unordered_map<string, Shoes*>;
        }
    }  
    static void insertMap(const string &name, Shoes* obj)
    {
        shoesMap->insert(make_pair(name, obj));
    }
private:
    static unordered_map<string, Shoes*> *shoesMap;
};

unordered_map<string, Shoes*> * Shoes::shoesMap = nullptr;

// 耐克鞋子
class NiKeShoes : public Shoes
{
public:
    static const string typeName;
    void Show()
    {
        std::cout << "我是耐克球鞋，我的广告语：Just do it" << std::endl;
    }
};
const string NiKeShoes::typeName = "nike";


// 基类 衣服
class Clothe
{
public:
    virtual void Show() = 0;
    virtual ~Clothe() {}

    static Clothe *New(const string &type)
    {
        if(clotheMap->find(type) == clotheMap->end())
        {
            cout << "unKnown type " << type << endl;
            return nullptr;
        }
        else
        {
            return (*clotheMap)[type]; 
        }
    }

    static void initMap()
    {
        static bool map_existed = false;
        if(!map_existed)
        {
            clotheMap = new unordered_map<string, Clothe*>;
        }
    }  
    static void insertMap(const string &name, Clothe* obj)
    {
        clotheMap->insert(make_pair(name, obj));
    }
private:
    static unordered_map<string, Clothe*> *clotheMap; 
};
unordered_map<string, Clothe*> * Clothe::clotheMap = nullptr;


// 优衣库衣服
class UniqloClothe : public Clothe
{
public:
    static const string typeName;
    void Show()
    {
        std::cout << "我是优衣库衣服，我的广告语：I am Uniqlo" << std::endl;
    }
};
const string UniqloClothe::typeName = "Uniqlo";


template<class abstractType, class concreteType>
class addConstructorToMap
{
public:
    static concreteType *productNew()
    {
        return new concreteType;
    }
    addConstructorToMap(const string &lookup = concreteType::typeName)
    {
        abstractType::initMap();
        abstractType::insertMap(lookup, productNew());
    }
};


static addConstructorToMap<Shoes, NiKeShoes> addNIKEShoesToTable;
static addConstructorToMap<Clothe, UniqloClothe> addUniqloClotheToTable;