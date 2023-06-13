/**
 * Copyright (C), 2021-2023, github.com/lifei098909.
 * File: dynamic_programming.c
 * Created Time: 2021-xx-xx
 * Author: lifei (lifei1100508@163.com)
 */

#ifndef __COMMON_H
#define __COMMON_H

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

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

int cmp_twodimension(const void *a, const void *b)
{
    int *a1 = *(int **)a;
    int *b1 = *(int **)b;
    if (a1[0] == b1[0]) {
        return a1[1] - b1[1];
    } else {
        return a1[0] - b1[0];
    }
}

int min_three(int a, int b, int c)
{
    return fmin(a, fmin(b, c));
}

int max_three(int a, int b, int c)
{
    return fmax(a, fmax(b, c));
}

/*
 * 二维数组第一列升序排序
*/
int comp_column_one(const void *a, const void *b)
{
    int *a1 = *(int **)a;
    int *b1 = *(int **)b;
    
    return a1[0] - b1[0]; 
}

/*
 * 二维数组第二列升序排序
*/
int comp_column_two(const void *a, const void *b)
{
    int *a1 = *(int **)a;
    int *b1 = *(int **)b;
    
    return a1[1] - b1[1]; 
}


#endif