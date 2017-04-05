
// Source : https://leetcode.com/problems/merge-two-sorted-lists/
// Author : lixianmin?live.cn
// Date   : 2017-03-27

/**********************************************************************************
 * Merge two sorted linked lists and return it as a new list. The new list should
 * be made by splicing together the nodes of the first two lists.
**********************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <deque>
#include <string>
#include <vector>
#include <unordered_map>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution
{
public:
    ListNode* mergeTwoLists (ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);
        ListNode *p = &dummy;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }

            p = p->next;
        }

        p->next = NULL != l1 ? l1 : l2;
        return dummy.next;
    }
};

void test (ListNode* l1, ListNode* l2)
{
    Solution processor;
    ListNode* merged= processor.mergeTwoLists(l1, l2);
    ListNode* p = merged;
    while (p)
    {
        printf("%d->", p->val);
        p = p->next;
    }

    printf("\n");
}

int main ()
{
    ListNode* l1 = new ListNode(1, new ListNode(3, new ListNode(5)));
    ListNode* l2 = new ListNode(2, new ListNode(4, new ListNode(6, new ListNode(8, new ListNode(10)))));

    // ListNode* l1 = new ListNode(5, new ListNode(3, new ListNode(1)));
    // ListNode* l2 = new ListNode(12, new ListNode(10, new ListNode(9, new ListNode(4, new ListNode(2)))));
    test (l1, l2);

    printf("\n");
}
