
// Source : https://leetcode.com/problems/3sum/
// Author : lixianmin?live.cn
// Date   : 2017-03-22

/**********************************************************************************
 * Given an array S of n integers, are there elements a, b, c in S such that
 * a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note: The solution set must not contain duplicate triplets.
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * A solution set is:
 * [
 *      [-1, 0, 1],
 *      [-1, -1, 2]
 * ]
**********************************************************************************/

#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::vector<int> > threeSum(std::vector<int>& nums)
    {
        std::vector<std::vector<int> > result;

        std::sort(nums.begin(), nums.end());
        int count = nums.size();

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
                if (sum < 0)
                {
                    mid++;
                }
                else if (sum == 0)
                {
                    _CheckAdd(result, a, b, c);
                    mid++;
                    right--;
                }
                else
                {
                    right--;
                }
            }
        }

        return result;
    }

private:
    void _CheckAdd (std::vector< std::vector<int> >& result, int a, int b, int c)
    {
        bool isFound = false;

        for (int j= result.size()-1; j>=0; --j)
        {
            std::vector<int>& current = result[j];
            if (current[0] < a)
            {
                break;
            }

            if (current[0] == a && current[1] == b && current[2] == c)
            {
                return;
            }
        }

        std::vector<int> v(3, 0);
        v.clear();

        v.push_back(a);
        v.push_back(b);
        v.push_back(c);

        result.push_back(v);
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

    printf("[\n");
    std::vector<std::vector<int> > result = processor.threeSum(v);
    for (int i= 0; i<result.size(); ++i)
    {
        std::vector<int>& v = result[i];

        printf("  [");
        for (int j= 0; j< v.size();++j)
        {
            printf("%d, ", v[j]);
        }
        printf("]\n");
    }
    printf("]\n");
    // printf("%s ==> %s\n", s.c_str(), processor.convert(s, numRows).c_str());
}

int main ()
{
    int a[] = {-1, 0, 1, 2, -1, -4};
    test (a, sizeof(a)/sizeof(a[0]));

    int b[] = {-1, 0, 1, 2, -1, -4, 4, 3, 1, -1, -1, 5, 6, 0, 2};
    test (b, sizeof(b)/sizeof(b[0]));

    int c[] = {-2, 0, 1, 1, 2};
    test (c, sizeof(c)/sizeof(c[0]));

    printf("\n");
}
