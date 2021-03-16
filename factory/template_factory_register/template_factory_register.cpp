#include "template_factory_register.h"

int main()
{
    // 1. 注册产品
    productRegister<Shoes, NiKeShoes> NIKEShoesRegister("nike");
    // 获取工厂实例
    Shoes *NIKE = abstractFactory<Shoes>::getInstance()->findObject("nike");
    NIKE->Show();
    
    system("pause");
}