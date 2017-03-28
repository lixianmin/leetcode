
// Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Author : lixianmin?live.cn
// Date   : 2017-03-23

/**********************************************************************************
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * Find the minimum element.
 * You may assume no duplicate exists in the array.
**********************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int findMin (std::vector<int>& nums)
    {
        int count = nums.size();
        if (count == 0)
        {
            return -1;
        }

        int left = 0;
        int right = count - 1;
        int min = nums[0];

        while (left <= right)
        {
            int mid = (left + right) >> 1;
            int item = nums[mid];

            if (item < nums[left])
            {
                min = std::min(item, min);
                right = mid -1;
            }
            else
            {
                min = std::min(nums[left], min);
                left = mid + 1;
            }
        }

        return min;
    }
};

void test (int a[], int count)
{
    Solution processor;
    std::vector<int> v;
    for (int i= 0; i< count; ++i)
    {
        v.push_back(a[i]);
    }

    int result = processor.findMin(v);
    printf("%d\n", result);
    // printf("%s ==> %s\n", s.c_str(), processor.convert(s, numRows).c_str());
}

int main ()
{
    int a[] = {4, 5, 6, 7, 0, 1, 2};
    test (a, sizeof(a)/sizeof(a[0]));

    int b[] = {4, 5, 6, 1, 2, 3};
    test (b, sizeof(b)/sizeof(b[0]));

    printf("\n");
}
