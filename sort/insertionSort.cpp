#include "randomNumGenerator.h"

void insertToRightPos(vector<int> &nums, int i)
{
    int tmp = nums[i];
    // 找到插入的合适位置并将插入位置后面的元素全部后移
    while(i > 0 && tmp < nums[i-1])
    {
        nums[i] = nums[i-1];
        i--;
    }
    nums[i] = tmp;
}

int main()
{
    int len = nums.size();
    // i左边是已经排序好的元素
    for(int i = 1; i < len; ++i)
    {
        insertToRightPos(nums, i);
    }
    display();
}

