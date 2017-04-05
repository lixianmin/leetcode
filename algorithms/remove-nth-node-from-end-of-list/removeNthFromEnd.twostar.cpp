
// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author : lixianmin?live.cn
// Date   : 2017-04-05

/**********************************************************************************
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 * Given linked list: 1->2->3->4->5, and n = 2.  After removing the second node
 * from the end, the linked list becomes 1->2->3->5.
 *
 * Note: Given n will always be valid.  Try to do this in one pass.
 **********************************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <numeric>
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


    void Print()
    {
        ListNode* head = this;
        while (head)
        {
            printf("%d->", head->val);
            head = head->next;
        }

        printf("\n");
    }
};

class Solution
{
public:
    ListNode* removeNthFromEnd (ListNode* head, int n)
    {
        if (NULL == head || n <= 0)
        {
            return head;
        }

        ListNode *first= head, **second= &head;
        for (int i= 0; i< n && first; ++i)
        {
            first = first->next;
        }

        while (first)
        {
            first = first->next;
            second = &(*second)->next;
        }

        ListNode* pOld = *second;
        *second = (*second)->next;
        delete pOld;

        return head;
    }
};

void test (ListNode* head, int n)
{
    Solution processor;
    ListNode* list = processor.removeNthFromEnd(head, n);
    list->Print();

    ListNode* p = list;
    while (p)
    {
        ListNode* q = p;
        p = p->next;
        delete q;
    }
}

int main ()
{
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    test(head, 2);

    head = new ListNode(1, new ListNode(2));
    test(head, 1);

    head = new ListNode(1, new ListNode(2));
    test(head, 2);

    head = new ListNode(1);
    test(head, 1);

    printf("\n");
}
