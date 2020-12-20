#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

/* leetcode 206 start */
/*
 * leetcode 206.反转链表
 * 反转一个单链表。
 * 示例:
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 */
struct ListNode* reverseList(struct ListNode* head){
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
struct ListNode* reverseList_a(struct ListNode* head)
{
   if (!head || !head->next)
        return head;
    struct ListNode* last = reverseList_a(head->next); //last指针记录链表末尾节点
    head->next->next = head;
    head->next = NULL;
    return last;
}
/* leetcode 206 end */

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
    head = reverseList_a(&a);
    printf("After reverse : \n");
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
}
