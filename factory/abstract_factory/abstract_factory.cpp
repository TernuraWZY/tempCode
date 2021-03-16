#include "abstract_factory.h"

int main()
{
    abstractFactory *NIKEFactory1 = new NIKEFactory();

    Shoes *NIKEshoes = NIKEFactory1->createShoes();
    NIKEshoes->Show();
    Clothe *NIKEClothe = NIKEFactory1->createClothe();
    NIKEClothe->Show();

    delete NIKEshoes;
    delete NIKEClothe;
    delete NIKEFactory1;
    system("pause");
}