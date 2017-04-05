
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
        if (NULL == head || NULL == head->next)
        {
            return head;
        }

        ListNode *a = head, *b = head->next, *newHead = b, *c= NULL, *tail = NULL;

        while (NULL != a && NULL != b)
        {
            c = b->next;
            b->next = a;
            a->next = NULL;

            if (NULL != tail)
            {
                tail->next = b;
            }

            tail = a;
            a = c;
            b = NULL != a ? a->next : NULL;
        }

        if (NULL != a)
        {
            tail->next = a;
        }

        return newHead;
    }

private:
    ListNode* _ReverseList (ListNode* head, ListNode* tail)
    {
        if (NULL == head || NULL == head->next)
        {
            return head;
        }

        ListNode *a = head, *b = head->next, *c = NULL;
        a->next = NULL;

        while (NULL != a && NULL != b && a != tail)
        {
            c = b->next;
            b->next = a;

            a = b;
            b = c;
        }

        return a;
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
