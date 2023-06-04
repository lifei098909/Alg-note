### 1.数组
  数组，就是用一个统一的名字代表这批数据，而用序号或下标来代表各个数据。数组是最简单和基本的一种数据结构。
数组中的元素再内存中是连续存储的，并且每个元素占用相同的内存。在刷题时，也是最容易上手的，leetcode里对应的题目如下：

### 1.1 两数之和
[leetcode 1.两数之和](https://leetcode-cn.com/problems/two-sum/)

**题目描述**

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 **和为目标值** target  的那 **两个** 整数，并返回它们的数组下标。你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。你可以按任意顺序返回答案。

**解题思路**

题目很容易看懂，最简单的方法就是两层for循环查找的暴力解法。

```cpp
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    static int a[2] = {0};

    *returnSize = 2;
    for(int i = 0; i < numsSize-1; i++)
    {
        for(int j = i + 1; j < numsSize; j++)
        {
            if((nums[i] + nums[j]) == target) {
                a[0] = i;
                a[1] = j;
                return a;
            }    
        }    
    }
    return a;
}
```

### 1.2 删除有序数组中的重复项

[leetcode 26.删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

**题目描述**

给你一个有序数组 nums ，请你 **原地** 删除重复出现的元素，使每个元素 **只出现一次** ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 **原地 修改输入数组** 并在使用 O(1) 额外空间的条件下完成。
**题目解析**

根据题目描述，在删除重复元素之后，每个元素只出现一次，且必须原地修改数组，可以考虑双指针方法，**num[i]** 循环递增，
如果 **nums[cnt] != nums[i]** 时，即为数组中的非重复项，则保存 **num[i]** 的值，否则未保存，就会被后续覆盖。

```cpp
int removeDuplicates(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0)
        return 0;
    int cnt = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[cnt] != nums[i])
            nums[++cnt] = nums[i];
    }
    return cnt + 1;
}
```
