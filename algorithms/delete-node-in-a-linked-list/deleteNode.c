
// Source : https://leetcode.com/problems/delete-node-in-a-linked-list/
// Author : lixianmin?live.cn
// Date   : 2017-04-15

/**********************************************************************************
* Write a function to delete a node (except the tail) in a singly linked list, given
* only access to that node.
*
* Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with
* value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
**********************************************************************************/

#include "basic.h"
#include "linkedlist.h"

void deleteNode (struct ListNode* node) {
    if (node) {
        struct ListNode* next = node->next;
        *node = *next;
        free (next);
    }
}

void test (struct ListNode* head, struct ListNode* node) {
    list_print ("before delete:", head);
    deleteNode (node);
    list_print ("after delete:", head);
    printf ("----------------------------\n");
}

int main ()
{
    int a1[] = {1, 2, 3, 3, 2, 1 };
    struct ListNode* l1 = list_create (a1, sizeof(a1)/sizeof(a1[0]));
    test (l1, l1->next);

    int a2[] = {1, 2, 3, 2, 1};
    struct ListNode *l2 = list_create (a2, sizeof a2 /sizeof a2[0]);
    test (l2, l2->next->next->next);

    struct ListNode* l3 = NULL;
    test (l3, l3);

    printf("\n");
}
