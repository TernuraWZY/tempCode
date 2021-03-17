#include "template_factory_register.h"

int main()
{
    // 1. 注册产品
    productRegister<Shoes, NiKeShoes> NIKEShoesRegister("nike");
    productRegister<Clothe, UniqloClothe> UniqloRegister("Uniqlo");
    // 获取工厂实例
    Shoes *NIKE = abstractFactory<Shoes>::getInstance()->findObject("nike");
    NIKE->Show();
    
    Clothe *uniqlo = abstractFactory<Clothe>::getInstance()->findObject("Uniqlo");
    uniqlo->Show();
    system("pause");
}