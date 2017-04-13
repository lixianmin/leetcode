
/********************************************************************
created:    2017-04-13
author:     lixianmin

Copyright (C) - All Rights Reserved
*********************************************************************/

#ifndef PANDA_LINKED_LIST
#define PANDA_LINKED_LIST

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* list_create (int* values, int count);
void list_destroy (struct ListNode** node);

struct ListNode* list_reverse (struct ListNode *first, struct ListNode *last);
void list_print (const char* title, struct ListNode *head);

#endif
