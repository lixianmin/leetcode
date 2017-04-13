
/********************************************************************
created:    2017-04-13
author:     lixianmin

Copyright (C) - All Rights Reserved
*********************************************************************/

#include "basic.h"
#include "linkedlist.h"

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

struct ListNode* list_reverse (struct ListNode *first, struct ListNode *last)
{
    struct ListNode *h = NULL, *p = NULL;
    while (first != last)
    {
        p = first->next;
        first->next = h;
        h = first;
        first= p;
    }

    return h;
}


