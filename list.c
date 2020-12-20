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
struct ListNode *reverseN(struct ListNode* head, int n)
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

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
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
struct ListNode* reverseList_ab(struct ListNode* a, struct ListNode *b)
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

struct ListNode* reverseKGroup(struct ListNode* head, int k){
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
bool isPalindrome(struct ListNode* head){
    struct ListNode *left = head;
    struct ListNode *right = reverse(head);

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
