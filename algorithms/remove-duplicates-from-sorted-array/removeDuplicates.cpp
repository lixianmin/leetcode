
// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : lixianmin?live.cn
// Date   : 2017-03-27

/**********************************************************************************
 * Given a sorted array, remove the duplicates in place such that each element appear
 * only once and return the new length.  Do not allocate extra space for another
 * array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
**********************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int removeDuplicates (std::vector<int>& nums)
    {
        int count = nums.size();
        if (count <= 1)
        {
            return count;
        }

        int tail = 0, head = 1;
        while (tail < head && head < count)
        {
            if (nums[head] != nums[tail])
            {
                ++tail;
                nums[tail] = nums[head];
            }

            ++head;
        }

        return tail + 1;
    }
};

void test (int data[], int length)
{
    std::vector<int> v;
    for (int i= 0; i< length; ++i)
    {
        v.push_back(data[i]);
    }

    Solution processor;
    int newCount = processor.removeDuplicates(v);

    printf("%d => [", newCount);
    for (int i= 0; i< newCount; ++i)
    {
        printf("%d, ", v[i]);
    }
    printf("]\n");
}

int main ()
{
    int data[] = {1, 1, 1, 2, 3, 3, 4, 4, 5, 6, 6, 6, 6, 7, 8, 8, 9, 9, 9};
    test(data, sizeof(data)/sizeof(data[0]));

    int data1[] = {9, 9, 9, 8, 8, 8, 7, 7, 6, 5, 4, 3, 3, 2, 1};
    test(data1, sizeof(data1)/sizeof(data1[0]));

    int data2[] = {9, 8};
    test(data2, sizeof(data2)/sizeof(data2[0]));


    int data3[] = {1};
    test(data3, sizeof(data3)/sizeof(data3[0]));

    printf("\n");
}
