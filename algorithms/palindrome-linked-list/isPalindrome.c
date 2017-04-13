
// Source : https://leetcode.com/problems/palindrome-linked-list/
// Author : lixianmin?live.cn
// Date   : 2017-04-13

/**********************************************************************************
 * Reverse a singly linked list.
**********************************************************************************/

#include "basic.h"
#include "linkedlist.h"

bool isPalindrome(struct ListNode* head)
{
    if (NULL == head || NULL == head->next)
    {
        return true;
    }

    struct ListNode **slow = &head, *fast = head;
    while (fast && (fast = fast->next))
    {
        slow = &(*slow)->next;
        fast = fast->next;
    }

    struct ListNode **mid = slow;
    struct ListNode *half = list_reverse(*slow, NULL);

    bool result = true;
    struct ListNode *p = head, *q = half;
    while (q)
    {
        if (p->val != q->val)
        {
            result = false;
            break;
        }

        p = p->next;
        q = q->next;
    }

    *mid = list_reverse(half, NULL);
    return result;
}

void test (struct ListNode** head)
{
    bool result = isPalindrome (*head);
    printf ("result = %d \n", result);
    printf ("----------------------------\n");

    list_destroy (head);
}

int main ()
{
    int a1[] = {1, 2, 3, 3, 2, 1 };
    struct ListNode* l1 = list_create (a1, sizeof(a1)/sizeof(a1[0]));

    int a2[] = {1, 2, 3, 2, 1};
    struct ListNode *l2 = list_create (a2, sizeof a2 /sizeof a2[0]);

    struct ListNode* l3 = NULL;

    int a4[] = {1};
    struct ListNode *l4 = list_create (a4, sizeof a4 /sizeof a2[0]);

    test (&l1);
    test (&l2);
    test (&l3);
    test (&l4);

    printf("\n");
}
