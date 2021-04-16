#include "randomNumGenerator.h"

// 将堆顶元素放到合适的位置
void downAdjust(vector<int> &nums, int parentIndex, int len)
{
    int tmp = nums[parentIndex];
    int childIndex = 2*parentIndex+1;
    while(childIndex < len)
    {
        // 如果有右孩子并且右孩子值大于左孩子，那么定位右孩子
        if(childIndex+1 < len && nums[childIndex+1] > nums[childIndex])
            childIndex++;
        // 如果父节点值大于左右孩子，那么直接跳出(大顶堆)
        if(tmp >= nums[childIndex])
            break;

        // 无需真正交换，只需要单向赋值
        nums[parentIndex] = nums[childIndex];
        parentIndex = childIndex;
        childIndex = 2*childIndex+1;
    }
    nums[parentIndex] = tmp;
}

void Sort(vector<int> &nums)
{
    int len = nums.size();
    for(int i = len/2-1; i >= 0; --i)
        downAdjust(nums, i, len);
    
    for(int i = len-1; i > 0; --i)
    {
        int tmp = nums[i];
        nums[i] = nums[0];
        nums[0] = tmp;
        downAdjust(nums, 0, i);
    }
}

int main()
{
    cout << "\nold" << endl;
    display();
    int len = nums.size();
    Sort(nums);
    // Sort(nums);
    cout << "\nnew" << endl;
    display();
}
