
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


int main ()
{
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode **pp = &head;

    ListNode *a = *pp;
    ListNode *b = a->next;

    a->next = b->next;
    b->next = a;

    *pp = b;
    // pp = &(a->next);

    head->val = 200;
    // b->val = 300;

    printf("head=%d, a->val=%d, b->val=%d, (*pp)->val=%d\n", head->val, a->val, b->val, (*pp)->val);
    head->Print();

    printf("\n");
}
