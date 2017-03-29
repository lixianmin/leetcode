
// Source : https://leetcode.com/problems/3sum/
// Author : lixianmin?live.cn
// Date   : 2017-03-28

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

        for (int i= 0; i< count; ++i)
        {
            int target = -nums[i];
            int low = i + 1;
            int high = count - 1;

            while (low < high)
            {
                int sum = nums[low] + nums[high];
                if (sum < target)
                {
                    ++low;
                }
                else if (sum > target)
                {
                    --high;
                }
                else
                {
                    std::vector<int> v(3, 0);
                    v[0] = nums[i];
                    v[1] = nums[low];
                    v[2] = nums[high];
                    result.push_back(v);

                    // 下面这两行分别是v[1], v[2]越过相同项
                    while (low < high && nums[low] == v[1]) ++low;
                    while (low < high && nums[high] == v[2]) --high;
                }
            }

            // 下面这行是v[0]越过相同项，注意最上面for()循环体内还有一个++i
            while (i+1 < count && nums[i] == nums[i+1]) ++i;
        }

       return result;
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
    // test (b, sizeof(b)/sizeof(b[0]));

    int c[] = {-2, 0, 1, 1, 2};
    // test (c, sizeof(c)/sizeof(c[0]));

    printf("\n");
}
