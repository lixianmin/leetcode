
// Source : https://leetcode.com/problems/copy-list-with-random-pointer/
// Author : lixianmin?live.cn
// Date   : 2017-03-24

/**********************************************************************************
 * A linked list is given such that each node contains an additional random pointer
 * which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
**********************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <unordered_map>

// Definition for singly-linked list with a random pointer.
struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
public:
    RandomListNode *copyRandomList (RandomListNode *head)
    {
        if (NULL == head)
        {
            return NULL;
        }

        std::unordered_map<RandomListNode*, RandomListNode*> m;

        RandomListNode *p = head;
        while (p)
        {
            m[p] = new RandomListNode(p->label);
            p = p->next;
        }

        p = head;
        RandomListNode *result = m[head], *q = result;

        while (NULL != p)
        {
            RandomListNode *next = p->next, *random = p->random;
            if (NULL != next)
            {
                q->next = m[next];
            }

            if (NULL != random)
            {
                q->random = m[random];
            }

            p = next;
            q = q->next;
        }

        return result;
    }
};

void PrintList (RandomListNode* p)
{
    while (p)
    {
        printf("(%d, %d)->", p->label, p->random? p->random->label : -1);
        p = p->next;
    }

    printf("\n");
}

int main ()
{
    RandomListNode* p = new RandomListNode(1);
    p->next = new RandomListNode(2);
    p->next->next = new RandomListNode(3);
    p->next->next->next = new RandomListNode(4);

    p->random = p->next->next;
    p->next->random = p->next->next;
    p->next->next->random = p;
    p->next->next->next->random = p->next->next->next;

    Solution processor;
    RandomListNode* copied = processor.copyRandomList(p);

    PrintList(p);
    PrintList(copied);

    printf("\n");
}
