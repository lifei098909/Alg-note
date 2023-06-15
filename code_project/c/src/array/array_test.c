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
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[size - 1]);
}

/* 查找元素 */
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

/* 遍历数组 */
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

/* 在数组中index位置插入data*/
int insert_element(int *arr, int size, int index, int data)
{
    for (int i = size - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = data;
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

    /* 插入元素 */
    insert_element(nums, size, 2, 101);
    printf("在索引 2 处插入数字 101 ，得到 nums = ");
    print_array(nums, size);
}

int main(void)
{
    array_test();

    return 0;
}
