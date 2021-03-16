#include "simple_factory.h"

int main()
{
    shoesFactory shoesFac;
    shoes *m_shoes = shoesFac.CreateShoes(NIKE);
    m_shoes->show();
    system("pause");
}