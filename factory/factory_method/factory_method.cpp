#include "factory_method.h"

int main()
{
    // 阿迪达斯工厂及生产
    AbstractShoesFactory *adidasFactory = new AdidasShoesFactory();
    shoes *adidasShoes = adidasFactory->CreateShoes();
    adidasShoes->show();

    // 阿迪达斯工厂及生产
    AbstractShoesFactory *NIKEFactory = new NIKEShoesFactory();
    shoes *NIKEShoes = NIKEFactory->CreateShoes();
    NIKEShoes->show();

    // 阿迪达斯工厂及生产
    AbstractShoesFactory *LiNingFactory = new LiNingShoesFactory();
    shoes *LiNingShoes = LiNingFactory->CreateShoes();
    LiNingShoes->show();

    system("pause");
}