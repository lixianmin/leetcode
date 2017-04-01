
// Source : https://leetcode.com/problems/merge-k-sorted-lists/
// Author : lixianmin?live.cn
// Date   : 2017-04-01

/**********************************************************************************
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
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

        ListNode* result = _partition (lists, 0, count-1);
        return result;
    }

private:
    ListNode* _partition (std::vector<ListNode*>& lists, int startIndex, int endIndex)
    {
        if (startIndex == endIndex)
        {
            return lists[startIndex];
        }

        int mid = (startIndex + endIndex) / 2;
        ListNode* left = _partition (lists, startIndex, mid);
        ListNode* right = _partition (lists, mid + 1, endIndex);

        ListNode* result = _mergeTwoLists(left, right);
        return result;
    }

    ListNode* _mergeTwoLists (ListNode* l1, ListNode* l2)
    {
        ListNode preHead(0);
        ListNode *p = &preHead;

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
        return preHead.next;
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

    printf("\n");
}
