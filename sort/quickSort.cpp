#include "randomNumGenerator.h"

void changePos(vector<int> &nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
} 

void Sort(vector<int> &nums, int left, int right)
{
    if(left >= right)
        return;    
    // 随机取位置
    srand(time(NULL));
    int pos = rand()%(right-left+1)+left;
    swap(nums[pos], nums[right]);

    int i = left, j = right-1;
    // 注意为什么要 <= 而不是 <
    // 如果出现对 2 3排序，此时i,j都指向2，发生交换就会让2,3失序
    while(i <= j)
    {
        while(i <= j && nums[i] <= nums[right])
            i++;
        while(i <= j && nums[j] >= nums[right])
            j--;
        if(i < j)
        changePos(nums, i, j);
    }
    // while(i < j)
    // {
    //     if(nums[i] <= nums[right])
    //         i++;
    //     else
    //     {
    //         swap(nums[i], nums[j]);
    //         j--;
    //     }        
    // }
    changePos(nums, i, right);
    Sort(nums, left, i-1);
    Sort(nums, i+1, right);
}

int main()
{
    cout << "\nold" << endl;
    display();
    int len = nums.size();
    Sort(nums, 0, len-1);
    // Sort(nums);
    cout << "\nnew" << endl;
    display();
}