
// Source : https://leetcode.com/problems/delete-node-in-a-linked-list/
// Author : lixianmin?live.cn
// Date   : 2017-04-15

/**********************************************************************************
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
**********************************************************************************/

#include "basic.h"
#include "linkedlist.h"

bool hasCycle (struct ListNode* head) {
    struct ListNode *p= head, *q= head;
    while (q && (q=q->next))
    {
        p = p->next;
        q = q->next;

        if (q == p) {
            return true;
        }
    }

    return false;
}

void test (struct ListNode* head) {
    bool result = hasCycle (head);
    printf ("---> head-val=%d, hasCycle=%d", head ? head->val : INT_MIN, result);
    printf ("----------------------------\n");
}

int main ()
{
    int a1[] = {1, 2, 3, 3, 2, 1 };
    struct ListNode* l1 = list_create (a1, sizeof(a1)/sizeof(a1[0]));
    l1->next->next->next->next->next->next = l1->next->next->next;
    test (l1);

    int a2[] = {2, 2, 3, 2, 1};
    struct ListNode *l2 = list_create (a2, sizeof a2 /sizeof a2[0]);
    test (l2);

    struct ListNode* l3 = NULL;
    test (l3);

    printf("\n");
}
