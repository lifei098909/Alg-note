/**
 * Copyright (C), 2021-2023, github.com/lifei098909.
 * File: list_test.c
 * Created Time: 2023-06-16
 * Author: lifei (lifei1100508@163.com)
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

typedef struct ListNode ListNode;

void test_list(void)
{
    struct ListNode a;
    struct ListNode b;
    struct ListNode c;
    struct ListNode d;
    struct ListNode e;
    a.val = 1;
    b.val = 2;
    c.val = 3;
    d.val = 4;
    e.val = 5;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;
}

int main(void)
{
    test_list();
    return 0;
}
