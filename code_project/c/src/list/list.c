/**
 * Copyright (C), 2021-2023, github.com/lifei098909.
 * File: list.c
 * Created Time: 2021-xx-xx
 * Author: lifei (lifei1100508@163.com)
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../../include/list.h"

/* leetcode 206 start */
/*
 * leetcode 206.反转链表
 * 反转一个单链表。
 * 示例:
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 */
static struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode *new_head = NULL;
    struct ListNode *next = NULL;
    while (head) {
        next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
    }
    return new_head;
}
/* 递归 */
static struct ListNode* reverseList_a(struct ListNode* head)
{
   if (!head || !head->next)
        return head;
    struct ListNode* last = reverseList_a(head->next); //last指针记录链表末尾节点
    head->next->next = head;
    head->next = NULL;
    return last;
}
/* leetcode 206 end */

/* leetcode 92 start */
/*
 * leetcode 92.反转链表II
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

 * 说明: 1 ≤ m ≤ n ≤ 链表长度。
 * 示例:
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
 */
struct ListNode *rear = NULL;
static struct ListNode *reverseN(struct ListNode* head, int n)
{
    if (n == 1) {
        rear = head->next;
        return head;
    }
    struct ListNode *last = reverseN(head->next, n - 1);
    head->next->next = head;
    head->next = rear;
    return last;
}

static struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    if (m == 1)
        return reverseN(head, n);
    head->next = reverseBetween(head->next, m - 1, n - 1);
    return head;
}
/* leetcode 92 end */


/* leetcode 25 start */
/*
 * leetcode 25. K 个一组翻转链表
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 示例：
 * 给你这个链表：1->2->3->4->5
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 */
static struct ListNode* reverseList_ab(struct ListNode* a, struct ListNode *b)
{
    struct ListNode* pre = NULL;
    struct ListNode* cur = a;
    struct ListNode* next = a;
    
    while (cur != b) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

static struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    if (head == NULL)
        return head;
    struct ListNode* a = head;
    struct ListNode* b = head;

    for (int i = 0; i < k; i++) {
        if (b == NULL)
            return head;
        b = b->next;
    }
    struct ListNode* newHead = reverseList_ab(a, b);
    a->next = reverseKGroup(b, k);
    
    return newHead;
}
/* leetcode 25 end */

/* leetcode 234 start */
/*
 * leetcode 234.回文链表
 * 请判断一个链表是否为回文链表。
 * 示例 1:
 * 输入: 1->2->2->1
 * 输出: true
 */
static bool isPalindrome(struct ListNode* head)
{
    struct ListNode *left = head;
    struct ListNode *right = reverseList(head);

    while (left ) {
        // printf("right->value = %d\n", right->val);
        if (left->val != right->val)
            return false;
        left = left->next;
        right = right->next;
    }
    return true;
}

/* leetcode 234 end */
void test_reverseList(void)
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

    struct ListNode *head = &a;
    printf("Before reverse : \n");
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    //head = reverseList_a(&a);
    //head = reverseN(&a, 3);
    //head = reverseBetween(&a, 2, 4);
    head = reverseKGroup(&a, 2);
    printf("After reverse : \n");
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
}

/* 剑指 Offer 22 start */
/*
 * 剑指 Offer 22. 链表中倒数第k个节点
 * 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，
 * 本题从1开始计数，即链表的尾节点是倒数第1个节点。
 * 例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。
 * 这个链表的倒数第3个节点是值为4的节点。
 * 示例：
 * 给定一个链表: 1->2->3->4->5, 和 k = 2.
 * 返回链表 4->5.
 */
static struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while (k-- > 0)
        fast = fast->next;

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
/* 剑指 Offer 22 start */

/*
 * leetcode 141 start
 * 环形链表
 * 给定一个链表，判断链表中是否有环。
 * 如果链表中存在环，则返回 true 。 否则，返回 false 。
 */
bool hasCycle(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return true;
    }
    return false;
}
/* leetcode 141 end */

/*
 * leetcode 142 start
 * 环形链表 II
 * 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null
 */
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *tmp = NULL;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast) {
            tmp = slow;
            break;
        } 
    }
    if (tmp == NULL)
        return NULL;

    slow = head;
    while (fast != slow) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
/* leetcode 142 end */

//相交链表 Leetcode 160
/*
 * leetcode 160 start
 * 相交链表
 * 编写一个程序，找到两个单链表相交的起始节点。
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) { 
    if (headA == NULL || headB == NULL)
        return NULL;

    struct ListNode *pA = headA;
    struct ListNode *pB = headB;

    while (pA != pB) {
        pA = ((pA == NULL) ? headB : pA->next);
        pB = ((pB == NULL) ? headA : pB->next);
    }
    return pA;
}
/* leetcode 160 end */


int main(void)
{
    test_reverseList();
    return 0;
}
