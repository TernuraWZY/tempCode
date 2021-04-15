#include <iostream>
#include <vector>
using namespace std;

vector<int> nums = {1, 2, 5, 6, 3, 1, 4, 3};

int main()
{
    int len = nums.size();
    // i左边是已经排序好的元素
    for(int i = 0; i < len; ++i)
    {
        int minIndex = i;
        // 找到未排序区间的最小元素，与i交换
        for(int j = i+1; j < len; ++j)
            if(nums[j] < nums[minIndex])
                minIndex = j;
        swap(nums[i], nums[minIndex]);
    }
    for(auto &it : nums)
        cout << it << " ";
}