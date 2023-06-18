/**
 * Copyright (C), 2021-2023, github.com/lifei098909.
 * File: dynamic_programming.c
 * Created Time: 2021-xx-xx
 * Author: lifei (lifei1100508@163.com)
 */

#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

struct ListNode {
     int val;
     struct ListNode *next;
};

/* Print a list */
void print_list(ListNode *node)
{
    if (node == NULL) {
        return;
    }

    while (node->next != NULL) {
        printf("%d -> ", node->val);
        node = node->next;
    }

    printf("%d\n", node->val);
}

void test_reverseList(void);

#ifdef __cplusplus
}
#endif

#endif