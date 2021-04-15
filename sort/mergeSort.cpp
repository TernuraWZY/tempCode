#include "randomNumGenerator.h"

void merge(vector<int> &nums, int left, int mid, int right);

// void Sort(vector<int> &nums, int left, int right)
// {
//     if(left < right)
//     {
//         int mid = left+(right-left)/2;
//         Sort(nums, left, mid);
//         Sort(nums, mid+1, right);
//         merge(nums, left, mid, right);
//     }
// }

void merge(vector<int> &nums, int left, int mid, int right)
{
    vector<int> tmp(right-left+1);
    int pos = 0;
    // 比较大小
    int i = left, j = mid+1;
    while(i <= mid && j <= right)
    {
        if(nums[i] < nums[j])
            tmp[pos++] = nums[i++];
        else
            tmp[pos++] = nums[j++];          
    }
    // 收尾
    while(i <= mid)
        tmp[pos++] = nums[i++];
    while(j <= right)
        tmp[pos++] = nums[j++];

    for(int idx = left; idx <= right; ++idx)
        nums[idx] = tmp[idx-left];
}

// 递归版本
void Sort(vector<int> &nums)
{
    int len = nums.size();
    // 子数组的大小分别为1，2，4，8...
    // 刚开始合并的数组大小是1，接着是2，接着4....
    for (int i = 1; i < len; i += i) 
    {
        //进行数组进行划分
        int left = 0;
        int mid = left + i - 1;
        int right = mid + i;
        //进行合并，对数组大小为 i 的数组进行两两合并
        while (right < len) 
        {
            // 合并函数和递归式的合并函数一样
            merge(nums, left, mid, right);
            left = right + 1;
            mid = left + i - 1;
            right = mid + i;
        }
        // 还有一些被遗漏的数组没合并，千万别忘了
        // 因为不可能每个字数组的大小都刚好为 i
        if (left < len && mid < len) {
            merge(nums, left, mid, len-1);
        }    
    }
}

int main()
{
    cout << "\nold" << endl;
    display();
    int len = nums.size();
    // Sort(nums, 0, len-1);
    Sort(nums);
    cout << "\nnew" << endl;
    display();
}