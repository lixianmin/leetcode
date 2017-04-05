
// Source : https://leetcode.com/problems/merge-k-sorted-lists/
// Author : lixianmin?live.cn
// Date   : 2017-03-29

/**********************************************************************************
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
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
    ListNode* mergeKLists (std::vector<ListNode*>& lists)
    {
        int count = lists.size();
        if (count == 0)
        {
            return NULL;
        }

        ListNode* result = lists[0];
        for (int i= 1; i< count; ++i)
        {
            result = mergeTwoLists(result, lists[i]);
        }

        return result;
    }

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

void test (std::vector<ListNode*>& v)
{
    Solution processor;
    ListNode* merged= processor.mergeKLists(v);
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
    ListNode* l1 = new ListNode(-12, new ListNode(3, new ListNode(13)));
    ListNode* l2 = new ListNode(2, new ListNode(4, new ListNode(6, new ListNode(20, new ListNode(30)))));
    ListNode* l3 = new ListNode(0, new ListNode(7, new ListNode(9, new ListNode(11, new ListNode(15)))));
    ListNode* l4 = new ListNode(-1, new ListNode(1, new ListNode(12, new ListNode(17, new ListNode(31)))));

    std::vector<ListNode*> v;
    v.push_back(l1);
    v.push_back(l2);
    v.push_back(l3);
    v.push_back(l4);

    // ListNode* l1 = new ListNode(5, new ListNode(3, new ListNode(1)));
    // ListNode* l2 = new ListNode(12, new ListNode(10, new ListNode(9, new ListNode(4, new ListNode(2)))));
    test (v);

    printf("\n");
}
