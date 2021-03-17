#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
using namespace std;

template<class concreteProductType>
class runTimeTable{
public:
    static unordered_map<string, concreteProductType*> *Map = nullptr; 

    static void initMap()
    {
        static bool map_existed = false;
        if(!map_existed)
        {
            Map = new unordered_map<string, concreteProductType*>;
        }
    }  
    static void add_map(const string &modelName ,const string &lookup, concreteProductType *conPro)  
    {
        // if(modelName == "shoes")
        // {
        //     shoesMap->insert(make_pair(lookup, absPro));
        // }
        // else if(modelName == "clothe")
        // {
        //     shoesMap->insert(make_pair(lookup, absPro));
        // }
        Map->insert(make_pair(lookup, conPro));
    }
};

template<class concreteProductType>
class addConstructToMap
{
public:
    static concreteProductType *productNew()
    {
        return new concreteProductType;
    }
    addConstructToMap(const string &modelName, const string &lookup = shoesType::typeName)
    {
        runTimeTable<concreteProductType>::initMap();
        runTimeTable<concreteProductType>::add_map(modelName, lookup, addConstructToMap::productNew());
    }
};

// 基类 鞋子
class Shoes
{
public:
    virtual void Show() = 0;
    virtual ~Shoes() {}

    static Shoes *New(const string &type)
    {
        if(runTimeTable::shoesMap->find(type) == runTimeTable::shoesMap->end())
        {
            cout << "unKnown type " << type << endl;
            return nullptr;
        }
        else
        {
            return (*runTimeTable::shoesMap)[type]; 
        }
    }
};

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

// 基类 衣服
class Clothe : public abstractProduct
{
public:
    virtual void Show() = 0;
    virtual ~Clothe() {}
};

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