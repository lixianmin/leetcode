
// Source : https://leetcode.com/problems/next-permutation/
// Author : lixianmin?live.cn
// Date   : 2017-04-17

/**********************************************************************************
 * Implement next permutation, which rearranges numbers into the lexicographically
 * next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible
 * order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 * Here are some examples. Inputs are in the left-hand column and its corresponding
 * outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
**********************************************************************************/

#include "basic.h"

/* 1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation. */
/* 2. Find the largest index l greater than k such that a[k] < a[l].                                                        */
/* 3. Swap the value of a[k] with that of a[l].                                                                             */
/* 4. Reverse the sequence from a[k + 1] up to and including the final element a[n].                                        */

void array_reverse (int* nums, int begin, int end) {
    if (nums && begin>= 0 && begin < end) {
        for (int i= begin, j= end-1; i<j; ++i, --j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}

void nextPermutation (int* nums, int numsSize) {
    if (!nums || numsSize <= 0) {
        return;
    }

    int k = -1;
    for (int i=numsSize-2; i>= 0; --i) {
        if (nums[i] < nums[i+1]) {
            k = i;
            break;
        }
    }

    if (k == -1) {
        array_reverse(nums, 0, numsSize);
        return;
    }

    int l = -1;
    for (int i= numsSize-1; i> k; --i) {
        if (nums[k] < nums[i]) {
            l = i;
            break;
        }
    }

    int temp = nums[k];
    nums[k] = nums[l];
    nums[l] = temp;

    array_reverse (nums, k+1, numsSize);
}

void array_print (const char* title, int* nums, int numsSize) {
    if (title) {
        fputs (title, stdout);
    }

    fputs ("[", stdout);
    for (int i= 0; i< numsSize; ++i) {
        printf ("%d, ", nums[i]);
    }
    fputs ("]\n", stdout);
}

void test (int* nums, int numsSize) {
    array_print ("before nextPermutation:", nums, numsSize);
    nextPermutation(nums, numsSize);
    array_print ("after nextPermutation:", nums, numsSize);
    fputs ("----------------------------\n", stdout);
}

int main ()
{
    char buffer[8] = {0};
    int nums[] = {1, 2, 3, 4 };
    const int numsSize = sizeof nums/sizeof nums[0];
    for (int i= 0; i< 24; ++i) {
        nextPermutation(nums, numsSize);
        sprintf(buffer, "%d : ", i);
        array_print (buffer, nums, numsSize);
    }

    printf("\n");
}
