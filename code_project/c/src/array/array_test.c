/**
 * Copyright (C), 2021-2023, github.com/lifei098909.
 * File: array_test.c
 * Created Time: 2023-06-14
 * Author: lifei (lifei1100508@163.com)
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../../include/array.h"
#include "../../include/common.h"

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int find_element(int arr[], int size, int target)
{
    if (arr == NULL || size < 0)
        return -1;

    for (int i = 0; i < size; i++) {
        if(arr[i] == target)
            return i;
    }
    return -1;
}

void traverse_array(int *arr, int size)
{
    if (arr == NULL || size < 0) {
        printf("the arr is null");
    }
    
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        cnt++;
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    printf("the arr cnt: %d", cnt);
}

void array_test(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6};
    int index;
    int size = ARRAY_SIZE(nums);

    index = find_element(nums, size, 5);
    if (index >= 0)
        printf("在数组nums中查找元素5 ，索引 index: %d\n", index);
    else
        printf("在数组nums中查找元素5 ，未找到该元素\n");

    traverse_array(nums, size);
}

int main(void)
{
    array_test();

    return 0;
}
