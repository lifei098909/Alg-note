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
    for (int i = 0; i < size; i++) {
        if(arr[i] == target)
            return i;
    }
    return -1;
}

void array_test(void)
{
    int size = 6;
    int nums[6] = {1, 2, 3, 4, 5, 6};
    int index;

    index = find(nums, size, 5);
    if (index >= 0)
        printf("在数组nums中查找元素5 ，索引为 %d\n", index);
    else
        printf("在数组nums中查找元素5 ，未找到\n");

}

int main(void)
{


}
