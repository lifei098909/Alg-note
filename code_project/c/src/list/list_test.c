/**
 * Copyright (C), 2021-2023, github.com/lifei098909.
 * File: list_test.c
 * Created Time: 2023-06-16
 * Author: lifei (lifei1100508@163.com)
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../../include/list.h"

typedef struct ListNode ListNode;

/* 初始化listnode */
ListNode *new_listnode(int val) 
{
    ListNode *node, *next;
    node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

/* 在链表中查找 target 节点 */
static int find_target(ListNode *node, int target)
{
    if (node == NULL)
        return -1;

    int i = 0;
    while (node) {
        if (node->val == target) {
            return i;
        }
        node = node->next;
        i++;
    }
    return -1;
}

/* 链表中插入节点 */
void insert_node(ListNode *head, ListNode *p)
{
    ListNode *n = head->next;
    p->next = n;
    head->next = p;
}

/* 遍历链表*/
static void traverse_node(ListNode *node)
{
    if (node == NULL)
        printf("the node is null");

    int cnt = 0;
    while (node) {
        cnt++;
        node = node->next;
    }

    printf("the node cnt: %d\n", cnt);;
}

void test_list(void)
{
    struct ListNode *a = new_listnode(1);
    struct ListNode *b = new_listnode(2);
    struct ListNode *c = new_listnode(3);
    struct ListNode *d = new_listnode(4);
    struct ListNode *e = new_listnode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = NULL;

    printf("初始化的链表为\r\n");
    print_list(a);

    int index = find_target(a, 3);
    if (index >= 0)
        printf("在数组nums中查找元素3 ，索引 index: %d\n", index);
    else
        printf("在数组nums中查找元素3 ，未找到该元素\n");

    /* 遍历链表 */
    traverse_node(a);
    /* 链表中插入节点 */
    insert_node(a, new_listnode(100));
    printf("insert node is\r\n");
    print_list(a);
}

int main(void)
{
    test_list();
    return 0;
}
