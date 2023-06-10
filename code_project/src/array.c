/*
* 
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/array.h"
#include "../include/common.h"

/* leetcode 1 start */
/*
 * leetcode 1.两数之和
 * 反转一个单链表。
 * 示例:
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 */
static int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    static int data[2] = {0};

    *returnSize = 2;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (data[i] + data[j] == target) {
                data[0] = i;
                data[1] = j;
                return data;
            }
        }
    }
    return data;
}

void test_twoSum(void)
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize = 0;
    int *res;
    res = twoSum(nums, ARRAY_SIZE(nums), 9, &returnSize);
    
    printf("test leetcode 1. twoSum, result is");
    for (int i = 0; i < returnSize; i++) {
        printf(" %d\n", res[i]);
    }

}
/* leetcode 1 end */

/* leetcode 283 start
 * 移动零
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 */
void moveZeroes(int* nums, int numsSize)
{
    int cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0)
            nums[cnt++] = nums[i];
    }

    while (cnt < numsSize)
        nums[cnt++] = 0;
}
/* leetcode 283 end */

/* leetcode 27 start
 * 移除元素
 * 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
 */
int removeElement(int* nums, int numsSize, int val)
{
    int cnt = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val)
            nums[cnt++] = nums[i];
    }

    return cnt;
}
/* leetcode 27 end */

/* leetcode 26 start
 * 移除元素
 * 给定一个排序数组，你需要在 原地 删除重复出现的元素，
 * 使得每个元素只出现一次，返回移除后数组的新长度。
 */
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
/* leetcode 26 end */

/* leetcode 80 start
 * 删除排序数组中的重复项 II
 * 给定一个增序排列数组 nums ，你需要在 原地 删除重复出现的元素，
 * 使得每个元素最多出现两次，返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须在 原地 修改输入数组 
 * 并在使用 O(1) 额外空间的条件下完成。
 */
int removeDuplicates_twonums(int* nums, int numsSize)
{
    if (numsSize <= 2)
        return numsSize;
    int index = 2;

    for (int i = 2; i < numsSize; i++) {
        if (nums[i] != nums[index - 2])
            nums[index++] = nums[i];
    }
    return index;
}
/* leetcode 80 end */

/* leetcode 75 start
 * 颜色分类
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，
 * 使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 */
void sortColors(int* nums, int numsSize){
    int zero = -1;
    int two = numsSize;
    int t;
    int i = 0;

    while (i < two) {
        if (nums[i] == 1) {
            i++;
        }
        else if (nums[i] == 2) {
            two--;
            t = nums[i];
            nums[i] = nums[two];
            nums[two] = t;
        }
        else {
            zero++;
            t = nums[i];
            nums[i] = nums[zero];
            nums[zero] = t;
            i++;
        }
    }
}
/* leetcode 75 end */

/* leetcode 215 start
 * 215. 数组中的第K个最大元素
 * 在未排序的数组中找到第 k 个最大的元素。
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 */
int quicksort(int *nums, int low, int high, int k)
{
    int temp = nums[low];
    int l = low;
    int h = high;

    while (low < high) {
        while (low < high && nums[high] >= temp) {
            high--;
        }
        nums[low] = nums[high];
        while (low < high && nums[low] <= temp) {
            low++;
        }
        nums[high] = nums[low];
    }
    nums[low] = temp;
    if (low == k)
        return nums[low];
    else if (low > k)
        return quicksort(nums, l, low - 1, k);
    else
        return quicksort(nums, low + 1, h, k);
}

int findKthLargest(int* nums, int numsSize, int k){
    return quicksort(nums, 0, numsSize - 1, numsSize - k);
}
/* leetcode 215 end */

int main(void)
{
    test_twoSum();
    return 0;
}

