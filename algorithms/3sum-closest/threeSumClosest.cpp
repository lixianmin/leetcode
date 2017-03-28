
// Source : https://leetcode.com/problems/3sum-closest
// Author : lixianmin?live.cn
// Date   : 2017-03-23

/**********************************************************************************
 * Given an array S of n integers, find three integers in S such that the sum is
 * closest to a given number, target. Return the sum of the three integers. You may
 * assume that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
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
    int threeSumClosest (std::vector<int>& nums, int target)
    {
        int count = nums.size();
        if (count <= 3)
        {
            int result = std::accumulate(nums.begin(), nums.end(), 0);
            return result;
        }

        std::sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];

        for (int left = 0; left < count; ++left)
        {
            int mid = left + 1;
            int right = count - 1;
            while (mid < right)
            {
                int a = nums[left];
                int b = nums[mid];
                int c = nums[right];

                int sum = a + b + c;
                int delta = sum - target;
                if (abs(delta) < abs(result - target))
                {
                    result = sum;
                }

                if (delta < 0)
                {
                    mid++;
                }
                else if (delta == 0)
                {
                    // printf("%d + %d + %d = %d, ", a, b, c, target);
                    return result;
                }
                else
                {
                    right--;
                }
            }
        }

        return result;
    }
};

void test (int a[], int count, int target)
{
    Solution processor;
    std::vector<int> v;
    for (int i= 0; i< count; ++i)
    {
        v.push_back(a[i]);
    }

    int result = processor.threeSumClosest(v, target);
    printf("%d\n", result);
    // printf("%s ==> %s\n", s.c_str(), processor.convert(s, numRows).c_str());
}

int main ()
{
    int a[] = {-1, 0, 1, 2, -1, -4};
    test (a, sizeof(a)/sizeof(a[0]), 4);

    int b[] = {-2, 1, 3, -3, 2, 7, 12};
    test (b, sizeof(b)/sizeof(b[0]), 9);

    int c[] = {1, 1, -1, -1, 3};
    test (c, sizeof(c)/sizeof(c[0]), -1);

    printf("\n");
}
