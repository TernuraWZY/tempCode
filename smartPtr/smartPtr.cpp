#include "smartPtr.h"
using namespace std;
class cal{
public:
    int x;
    int y;
    void showX() {cout << x << endl;}
    void showY() {cout << y << endl;}
    cal(int x_v, int y_v) : x(x_v), y(y_v) {}
};
int main()
{
    smartPtr<cal> smt(new cal(1, 2));
    smt->showX();
    system("pause");
}