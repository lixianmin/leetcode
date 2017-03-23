
// Source : https://leetcode.com/problems/container-with-most-water/
// Author : lixianmin?live.cn
// Date   : 2017-03-22

/**********************************************************************************
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at
 * coordinate (i, ai). n vertical lines are drawn such that the two endpoints of
 * line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms
 * a container, such that the container contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
**********************************************************************************/

#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int maxArea (std::vector<int>& height)
    {
        int count = height.size();
        int maxArea = 0;
        for (int i= 0; i< count; ++i)
        {
            for (int j= 0; j< count; ++j)
            {
                int h = std::min(height[i], height[j]);
                if (h == 0)
                {
                    continue;
                }

                int area = h * (j - i);
                if (area > maxArea)
                {
                    maxArea = area;
                }
            }
        }

        return maxArea;
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

    printf("[");
    printf("%d", processor.maxArea(v));
    printf("]\n");
}

int main ()
{
    int a[] = {0, 0, 2, 5, 7, 5, 0, 2, 0, 0, 0, 1};
    test (a, sizeof(a)/sizeof(a[0]));

    int b[] = {0, 1, 2, 3, 4, 3, 2, 1, 0 };
    test (b, sizeof(b)/sizeof(b[0]));

    printf("\n");
}
