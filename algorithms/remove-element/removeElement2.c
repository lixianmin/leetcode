
// Source : https://leetcode.com/problems/remove-element/
// Author : lixianmin?live.cn
// Date   : 2017-04-13

/**********************************************************************************
 * Given an array and a value, remove all instances of that value in place and
 * return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with
 * constant memory.  The order of elements can be changed. It doesn't matter what
 * you leave beyond the new length.
 *
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 *
 * Your function should return length = 2, with the first two elements of nums being 2.
**********************************************************************************/

#include "basic.h"

int removeElement (int* nums, int numsSize, int val)
{
    if (NULL == nums)
    {
        return 0;
    }

    int cnt = 0;
    for (int i= 0; i< numsSize; ++i)
    {
        if (nums[i] == val)
        {
            ++cnt;
        }
        else
        {
            nums[i-cnt] = nums[i];
        }
    }

    return numsSize - cnt;
}

void array_print (const char* title, int* nums, int numsSize)
{
    if (title)
    {
        printf("%-10s", title);
    }

    printf("[");
    for (int i= 0; i< numsSize; ++i)
    {
        printf("%d, ", nums[i]);
    }
    puts("]\n");
}

void test (int* nums, int numsSize, int val)
{
    int result = removeElement (nums, numsSize, val);
    array_print ("result=", nums, result);
    printf ("----------------------------\n");
}

int main ()
{
    int a1[] = {1, 2, 3, 3, 2, 1, 4 };
    test (a1, sizeof a1 /sizeof a1[0], 2);

    int a2[] = {1, 1, 1, 1};
    test (a2, sizeof a2 /sizeof a2[0], 1);

    printf("\n");
}
