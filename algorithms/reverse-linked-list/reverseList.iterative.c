
// Source : https://leetcode.com/problems/reverse-linked-list/
// Author : lixianmin?live.cn
// Date   : 2017-04-06

/**********************************************************************************
 * Reverse a singly linked list.
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

void list_node_print (struct ListNode *head)
{
    struct ListNode* p = head;
    while (p)
    {
        printf("%d->", p->val);
        p = p->next;
    }

    puts("\n");
}

struct ListNode* list_node_create (int val, struct ListNode* next)
{
    struct ListNode* node = (struct ListNode*) malloc (sizeof(struct ListNode));
    if (node)
    {
        node->val = val;
        node->next = next;
    }

    return node;
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
struct ListNode* reverseList (struct ListNode* head)
{
    struct ListNode *h = NULL, *p = NULL;
    while (head)
    {
        // 这个写法真是行云流水：每一行的右值，是下一行的左值
        p = head->next;
        head->next = h;
        h = head;
        head = p;
    }

    return h;
}

void test (struct ListNode* head)
{
    struct ListNode* result = reverseList(head);
    if (NULL != result)
    {
        list_node_print (result);
    }
}

int main ()
{
    struct ListNode* l1 = list_node_create(-12, NULL);
    struct ListNode* l2 = list_node_create(2, list_node_create(4, list_node_create(6, list_node_create(20, list_node_create(30, NULL)))));
    struct ListNode* l3 = list_node_create(-1, list_node_create(1, list_node_create(12, list_node_create(17, NULL))));
    struct ListNode* l4 = NULL;

    test (l1);
    test (l2);
    test (l3);
    test (l4);

    list_destroy(&l1);
    list_destroy(&l2);
    list_destroy(&l3);
    list_destroy(&l4);

    assert(!l1);
    assert(!l2);
    assert(!l3);
    assert(!l4);

    printf("\n");
}
