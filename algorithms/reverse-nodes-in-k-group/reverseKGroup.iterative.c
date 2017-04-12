
// Source : https://leetcode.com/problems/reverse-nodes-in-k-group/
// Author : lixianmin?live.cn
// Date   : 2017-04-12

/**********************************************************************************
 * Given a linked list, reverse the nodes of a linked list k at a time and return
 * its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the linked list.
 * If the number of nodes is not a multiple of k then left-out nodes in the end should
 * remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 *
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
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

struct ListNode* reverseList (struct ListNode *head, struct ListNode *tail)
{
    struct ListNode *h = NULL, *p = NULL, *tailNext = tail->next;
    while (head != tailNext)
    {
        p = head->next;
        head->next = h;
        h = head;
        head = p;
    }

    return h;
}

struct ListNode* reverseKGroup (struct ListNode* head, int k)
{
    if (NULL == head || k <= 1)
    {
        return head;
    }

    struct ListNode fake, *p = &fake;
    fake.next = head;

    while (p)
    {
        struct ListNode *tail = p;
        for (int i= 0; i< k; ++i)
        {
            tail = tail->next;

            if (!tail)
            {
                return fake.next;
            }
        }

        struct ListNode *face = p->next;
        struct ListNode *toe = tail->next;
        p->next = reverseList (face, tail);
        face->next = toe;

        p = face;
    }

    return fake.next;
}

void test (struct ListNode* head, int k)
{
    struct ListNode* result = reverseKGroup (head, k);
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

    test (l1, 3);
    test (l2, 2);
    test (l3, 2);

    list_destroy(&l1);
    list_destroy(&l2);
    list_destroy(&l3);

    printf("\n");
}
