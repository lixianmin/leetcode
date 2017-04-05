
// Source : https://leetcode.com/problems/merge-k-sorted-lists/
// Author : lixianmin?live.cn
// Date   : 2017-03-31

/**********************************************************************************
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
**********************************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <deque>
#include <queue>
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

struct ListNodeComparer
{
    bool operator() (const ListNode* lhs, const ListNode* rhs) const
    {
        return lhs->val > rhs->val;
    }
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

        std::vector<ListNode*> v;

        for (int i= 0; i< count; ++i)
        {
            ListNode* p = lists[i];
            if (NULL != p)
            {
                v.push_back(p);
            }
        }

        ListNodeComparer cmp;
        std::make_heap(v.begin(), v.end(), cmp);

        ListNode dummy(0), *p = &dummy;
        while (!v.empty())
        {
            p->next = v.front();
            p = p->next;

            std::pop_heap(v.begin(), v.end(), cmp);
            v.pop_back();

            if (NULL != p && NULL != p->next)
            {
                v.push_back(p->next);
                std::push_heap(v.begin(), v.end(), cmp);
            }
        }

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
    v.push_back(NULL);

    test (v);

    v.clear();
    l1 = new ListNode(0, new ListNode(2, new ListNode(5)));
    v.push_back(l1);
    test (v);


    printf("\n");
}
