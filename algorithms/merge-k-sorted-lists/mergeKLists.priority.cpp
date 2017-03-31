
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
    // 优先队列中，默认使用的是std::less<int>，然而此时是最大值先被pop()出
    // 我们希望的是最小值先被pop()出，因此需要使用类std::greater<int>规则
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

        typedef std::priority_queue<ListNode*, std::vector<ListNode*>, ListNodeComparer> PriorityQueue;
        PriorityQueue q;

        for (int i= 0; i< count; ++i)
        {
            ListNode* p = lists[i];
            if (NULL != p)
            {
                q.push(p);
            }
        }

        ListNode head(0), *p = &head;
        while (!q.empty())
        {
            p->next = q.top();
            p = p->next;
            q.pop();

            if (NULL != p->next)
            {
                q.push(p->next);
            }
        }

        return head.next;
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
