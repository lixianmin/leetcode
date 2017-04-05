
// Source : https://leetcode.com/problems/swap-nodes-in-pairs/
// Author : lixianmin?live.cn
// Date   : 2017-04-01

/**********************************************************************************
 * Reverse a singly linked list.
**********************************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
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

    void Print ()
    {
        ListNode* p = this;
        while (p)
        {
            printf("%d->", p->val);
            p = p->next;
        }

        puts("\n");
    }
};

class Solution
{
public:
    ListNode* swapPairs (ListNode* head)
    {
        ListNode **pp = &head, *a, *b;

        while ((a = *pp) && (b = a->next))
        {
            a->next = b->next;
            b->next = a;

            *pp = b;
            pp = &a->next;
        }

        return head;
    }
};

void test (ListNode* head)
{
    Solution processor;
    ListNode* result = processor.swapPairs(head);
    if (NULL != result)
    {
        result->Print();
    }
}

int main ()
{
    ListNode* l1 = new ListNode(-12);
    ListNode* l2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* l3 = new ListNode(-1, new ListNode(1, new ListNode(12, new ListNode(17))));
    ListNode* l4 = NULL;

    test (l1);
    test (l2);
    test (l3);
    test (l4);

    printf("\n");
}
