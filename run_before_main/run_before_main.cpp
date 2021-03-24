#include <iostream> 
using namespace std;

// __attribute((constructor))前缀
__attribute((constructor))void test0()
{
    printf("before main 0\n");
}
// 静态量编译器确定
int test1(){
	cout << "before main 1" << endl;
	return 54;
}
 
static int i = test1();
 
int main(int argc, char** argv) {
 
	cout << "main function." <<endl;
	return 0;
}