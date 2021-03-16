#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;
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
        std::cout << "我是耐克球鞋，我的广告语：Just do it" << std::endl;
    }
};

// 基类 衣服
class Clothe
{
public:
    virtual void Show() = 0;
    virtual ~Clothe() {}
};

// 优衣库衣服
class UniqloClothe : public Clothe
{
public:
    void Show()
    {
        std::cout << "我是优衣库衣服，我的广告语：I am Uniqlo" << std::endl;
    }
};

// 产品注册模板基类
template <class abstractProduct_t>
class interfaceRegister
{
public:
    // 获取产品对象
    virtual abstractProduct_t *createProduct() = 0;

protected:
    // 禁止外部构造析构
    interfaceRegister() {}
    virtual ~interfaceRegister() {}

private:
    // 禁止拷贝赋值
    interfaceRegister(const interfaceRegister &);
    const interfaceRegister &operator=(const interfaceRegister &);
};

// 工厂模板基类，静态方法
template <class abstractProduct_t>
class abstractFactory
{
public:
    // 单例模型                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
    static abstractFactory *getInstance()
    {
        static abstractFactory instance;
        return &instance;
    }
    abstractProduct_t *findObject(const string &name)
    {
        if (m_ProductRegistry.find(name) != m_ProductRegistry.end())
        {
            return m_ProductRegistry[name]->createProduct();
        }
        else
        {
            cout << "wrong key worrd" << endl;
        }
        return nullptr;
    }

    void registerProduct(interfaceRegister<abstractProduct_t> *registerObj, string name)
    {
        m_ProductRegistry[name] = registerObj;
    }

private:
    // 禁止外部构造
    abstractFactory() {}
    ~abstractFactory() {}

    abstractFactory(const abstractFactory &);
    const abstractFactory &operator=(const abstractFactory &);

    std::map<string, interfaceRegister<abstractProduct_t> *> m_ProductRegistry;
};

template <class abstractProduct_t, class concretProduct_t>
class productRegister : public interfaceRegister<abstractProduct_t>
{
public:
    explicit productRegister(const string &name)
    {
        abstractFactory<abstractProduct_t>::getInstance()->registerProduct(this, name);
    }

    abstractProduct_t *createProduct()
    {
        return new concretProduct_t();
    }
};