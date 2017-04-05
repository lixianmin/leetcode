
// Source : https://leetcode.com/problems/add-two-numbers
// Author : lixianmin#live.cn
// Date   : 2017-04-05

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

        int extra = 0;
        ListNode *head = NULL, **p= &head;
        while (NULL != l1 || NULL != l2 || extra != 0)
        {
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + extra;
            extra = sum/10;

            *p = new ListNode(sum%10);
            p = &(*p)->next;

            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }

        return head;
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
