
// Source : https://leetcode.com/problems/add-two-numbers
// Author : lixianmin#live.cn
// Date   : 2017-03-20

/**********************************************************************************
*
* You are given two non-empty linked lists representing two non-negative integers.
* The digits are stored in reverse order and each of their nodes contain a single
* digit. Add the two numbers and return it as a linked list.
*
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*
**********************************************************************************/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* addTwoNumbers (ListNode* l1, ListNode* l2)
    {
        if (NULL == l1)
        {
            return l2;
        }
        else if (NULL == l2)
        {
            return l1;
        }

        int left = 0;
        ListNode* first = NULL;
        ListNode* last = NULL;
        while (NULL != l1 && NULL != l2)
        {
            int sum = l1->val + l2->val + left;
            left = sum / 10;

            appendValue(first, last, sum - left * 10);
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* l = NULL != l1 ? l1 : l2;
        while (NULL != l)
        {
            int sum = l->val + left;
            left = sum / 10;
            appendValue(first, last, sum - left * 10);

            l = l->next;
        }

        if (0 != left)
        {
            appendValue(first, last, left);
        }

        return first;
    }

private:
    void appendValue (ListNode*& first, ListNode*& last, int val)
    {
        if (NULL != first)
        {
            last->next = new ListNode(val);
            last = last->next;
        }
        else
        {
            first = new ListNode(val);
            last = first;
        }
    }
};

int main ()
{
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(9, new ListNode(9, NULL))));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    Solution cpu;
    ListNode* p = cpu.addTwoNumbers(l1, l2);

    while (NULL != p)
    {
        printf("%d", p->val);
        p = p->next;
    }

    printf("\n");
}
