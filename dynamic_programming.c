#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dynamic_programming.h"
#include "common.h"

/* leetcode 70 start */
/*
 * leetcode 70.爬楼梯
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 */

int climbStairs(int n)
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

int fib(int N) {
    int dp[N + 1];
    if (N < 2)
        return N; 
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[N];
}

int fib_a(int N) {
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
