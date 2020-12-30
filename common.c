#include "common.h"

/* 从小到大排列 */
int comp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

/* 从大到小排列 */
int comb(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}