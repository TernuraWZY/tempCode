#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <vector>
using namespace std;
vector<int> generate()
{
    vector<int> tmp(100);
    srand(time(NULL));
    for(auto &it :tmp)
        it = rand()%50;
    return tmp;
}
vector<int> nums = generate();

void display()
{
    for(int i = 0; i < nums.size(); ++i)
    {
        if(i > 0 && i % 50 == 0)
        cout << endl;        
        cout << nums[i] << " ";
    }
}