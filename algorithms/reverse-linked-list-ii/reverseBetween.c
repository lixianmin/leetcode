
// Source : https://leetcode.com/problems/reverse-linked-list-ii
// Author : lixianmin?live.cn
// Date   : 2017-04-12

/**********************************************************************************
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 *
 * Subscribe to see which companies asked this question.
**********************************************************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////
struct ListNode
{
    int val;
    struct ListNode *next;
};

void list_print (const char* title, struct ListNode *head)
{
    if (title)
    {
        printf("%-10s", title);
    }

    struct ListNode* p = head;
    while (p)
    {
        printf("%d->", p->val);
        p = p->next;
    }

    puts("\n");
}

struct ListNode* list_create (int* values, int count)
{
    if (NULL == values || count < 0)
    {
        return NULL;
    }

    struct ListNode *head = NULL, **p= &head;
    for (int i= 0; i< count; ++i)
    {
        struct ListNode *current = (struct ListNode*) malloc (sizeof(struct ListNode));
        current->val = values[i];
        current->next = NULL;

        *p = current;
        p = &current->next;
    }

    return head;
}

void list_destroy (struct ListNode** node)
{
    while (*node)
    {
        struct ListNode* p = *node;
        *node = (*node)->next;
        free (p);
    }
}

//////////////////////////////////////////////////////////////////////////////////

struct ListNode* reverseBetween (struct ListNode* head, int m, int n)
{
    if (NULL == head || m < 1 || m > n)
    {
        return head;
    }

    n = n - m + 2;

    struct ListNode **p = &head, **rawHead= p;
    while (*p && --m)
    {
        p = &(*p)->next;
    }

    struct ListNode *face = *p, *foot = *p;
    while (foot && --n)
    {
        struct ListNode *move= foot->next;
        foot->next = *p;
        *p = foot;
        foot = move;
    }

    if (face)
    {
        face->next = foot;
    }

    return *rawHead;
}

void test (struct ListNode* head, int m, int n)
{
    struct ListNode* result = reverseBetween (head, m, n);
    if (NULL != result)
    {
        list_print ("result: ", result);
    }
}

int main ()
{
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    struct ListNode* l1 = list_create (a1, sizeof(a1)/sizeof(a1[0]));

    int a2[] = {1, 2};
    struct ListNode *l2 = list_create (a2, sizeof a2 /sizeof a2[0]);

    struct ListNode* l3 = NULL;

    test (l1, 20, 100);
    test (l1, 2, 5);
    test (l2, 1, 4);
    test (l3, 2, 4);

    list_destroy(&l1);
    list_destroy(&l2);
    list_destroy(&l3);

    printf("\n");
}
