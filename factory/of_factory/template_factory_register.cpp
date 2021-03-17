#include "template_factory_register.h"
const string NiKeShoes::typeName = "nike";
// const string UniqloClothe::typeName = "Uniqlo";

addConstructToMap<NiKeShoes> addNIKEShoesToTable;

int main()
{
    Shoes *nike = Shoes::New("nike");
    nike->Show();
    Shoes *nike1 = Shoes::New("NIKE");
    // abstractFactory<class abstractProduct_t>
    // initMap();
    // // // 1. 注册产品
    // productRegister<Shoes, NiKeShoes> NIKEShoesRegister("nike");
    // productRegister<Clothe, UniqloClothe> UniqloRegister("Uniqlo");
    // // 获取工厂实例
    // Shoes *NIKE = abstractFactory<Shoes>::getInstance()->findObject("nike");
    // NIKE->Show();
    
    // Clothe *uniqlo = abstractFactory<Clothe>::getInstance()->findObject("Uniqlo");
    // uniqlo->Show();
}