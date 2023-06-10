#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../include/dynamic_programming.h"
#include "../include/common.h"

/* leetcode 70 start */
/*
 * leetcode 70.爬楼梯
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 */

static int climbStairs(int n)
{
   int dp[n];

    if (n < 2)
        return n;
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}

void test_climbStairs(void) 
{
    int climb_ways;
    int len;
    int climb_data[] = {1, 2, 10, 12, 15, 20, 18, 31, 45};
    len = ARRAY_SIZE(climb_data);

    for (int i = 0; i < len; i++) {
        climb_ways = climbStairs(climb_data[i]);
        printf("we have %d ways to climb %d steps stairs\n", climb_ways, climb_data[i]);
    }
    climb_ways = climbStairs(climb_data[0]);
}
/* leetcode 70 end */

/* leetcode 509 start */
/*
 * leetcode 509.斐波那契数
 * 斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。
 * 该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
 * F(0) = 0,   F(1) = 1
 * F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
 */
static int fib(int N) {
    int dp[N + 1];
    if (N < 2)
        return N; 
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[N];
}

static int fib_a(int N) {
    if (N < 2)
        return N;
    return fib_a(N - 1) + fib_a(N - 2);
}

void test_fib(void)
{
    int fib_ways;
    int len;
    int fib_data[] = {1, 2, 10, 12, 15, 20, 18, 31, 45};
    len = ARRAY_SIZE(fib_data);

    for (int i = 0; i < len; i++) {
        fib_ways = fib(fib_data[i]);
        printf("we have %d ways to climb %d steps stairs\n", fib_ways, fib_data[i]);
    }
}
/* leetcode 509 end */

/* leetcode 300 start */
/*
 * leetcode 300.最长递增子序列
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 */
int lengthOfLIS(int* nums, int numsSize){
    int dp[numsSize];
    int res = 0;

    for (int i = 0; i < numsSize; i++) 
        dp[i] = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i] = fmax(dp[i], dp[j] + 1);
        }
    }
   
    for (int i = 0; i < numsSize; i++)
        res = fmax(res, dp[i]);
    return res;
}

void rest_lengthOfLIS(void)
{
    int res;
    int LIS_data[] = {10, 9, 2, 5, 7, 101, 18};
    
    res = lengthOfLIS(LIS_data, ARRAY_SIZE(LIS_data));

    printf("the length of LIS is %d\n", res);
}
/* leetcode 300 end */

/* leetcode 354 start */
/*
 * leetcode 354.俄罗斯套娃信封问题
 * 给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。
 * 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
 * 请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
 */
int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    if (envelopesSize == 0)
        return 0;
    
    qsort(envelopes, envelopesSize, sizeof(int*), cmp_twodimension);
    int dp[envelopesSize];
    int max = 0;

    for (int i = 0; i < envelopesSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (envelopes[i][0] > envelopes[j][0] && 
                envelopes[i][1] > envelopes[j][1])
                dp[i] = fmax(dp[i], dp[j] + 1);
        }
        max = fmax(max, dp[i]);
    }
    return max;
}
/* leetcode 354 end */

/* leetcode 53 start */
/*
 * leetcode 53.最大子序和
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 */
int maxSubArray(int* nums, int numsSize){
    int dp[numsSize + 1];

    if(numsSize == 0)
        return 0;
    dp[0] = nums[0];
    int res = nums[0];

    for (int i = 1; i < numsSize; i++) {
        dp[i] = fmax(nums[i], nums[i] + dp[i - 1]);
        res = fmax(res, dp[i]);
    }

    return res;
}
/* leetcode 53 end */

/* leetcode 72 start */
/*
 * leetcode 72.编辑距离
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 */
int minDistance(char * word1, char * word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++)
        dp[i][0] = i;
    for (int j = 0; j <= len2; j++)
        dp[0][j] = j;
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min_three(dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }
    return dp[len1][len2];
}
/* leetcode 72 end */

/* leetcode 516 start */
/*
 * leetcode 516.最长回文子序列
 * 给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 
 */
int longestPalindromeSubseq(char * s)
{
    int len = strlen(s);
    int dp[len];

    for (int i = 0; i < len; i++)
        dp[i] = 1;
    for (int i = len - 2; i >= 0; i--) {
        int pre = 0;
        for (int j = i + 1; j < len; j++) {
            int temp = dp[j];
            if (s[i] == s[j])
                dp[j] = pre + 2;
            else
                dp[j] = fmax(dp[j], dp[j - 1]);
            pre = temp;
        }
    }
    return dp[len - 1];
}
/* leetcode 516 start */

int main(void)
{
    test_climbStairs();
    test_fib();
    return 0;
}
