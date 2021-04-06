#include "template_factory_register.h"

int main()
{
    Shoes *nike = Shoes::New("nike");
    nike->Show();
    Shoes *nike1 = Shoes::New("NIKE");

    Clothe *uniqlo = Clothe::New("Uniqlo");
    uniqlo->Show();
    Clothe *uniqlo1 = Clothe::New("Uniqlo1");
}