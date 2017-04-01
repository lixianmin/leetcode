
// Source : https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList (ListNode* head)
    {
        if (NULL == head || NULL == head->next)
        {
            return head;
        }

        ListNode* body = head->next;
        ListNode* newHead = reverseList (body);
        body->next = head;
        head->next = NULL;

        return newHead;
    }
};

void test (ListNode* head)
{
    Solution processor;
    ListNode* result = processor.reverseList(head);
    if (NULL != result)
    {
        result->Print();
    }
}

int main ()
{
    ListNode* l1 = new ListNode(-12);
    ListNode* l2 = new ListNode(2, new ListNode(4, new ListNode(6, new ListNode(20, new ListNode(30)))));
    ListNode* l3 = new ListNode(-1, new ListNode(1, new ListNode(12, new ListNode(17))));
    ListNode* l4 = NULL;

    test (l1);
    test (l2);
    test (l3);
    test (l4);

    printf("\n");
}
