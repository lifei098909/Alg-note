/*
* 
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "array.h"
#include "common.h"

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
        printf(" %d", res[i]);
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

