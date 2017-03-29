
// Source : https://leetcode.com/problems/4sum
// Author : lixianmin?live.cn
// Date   : 2017-03-28

/**********************************************************************************
 * Given an array S of n integers, are there elements a, b, c, and d in S such that
 * a + b + c + d = target? Find all unique quadruplets in the array which gives the
 * sum of target.
 *
 * Note: The solution set must not contain duplicate quadruplets.
 *
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 * A solution set is:
 * [
 *  [-1,  0, 0, 1],
 *  [-2, -1, 1, 2],
 *  [-2,  0, 0, 2]
 * ]
**********************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <deque>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::vector<int> > fourSum(std::vector<int>& nums, int target)
    {
        std::vector<std::vector<int> > result;

        int count = nums.size();
        if (count < 4)
        {
            return result;
        }

        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > threeSumResult;

        for (int i= 0; i< count; ++i)
        {
            int tempTarget = target - nums[i];
            _threeSum(nums, threeSumResult, i+1, tempTarget);

            int threeSumResultCount = threeSumResult.size();
            if (threeSumResultCount > 0)
            {
                for (int j= 0; j< threeSumResultCount; ++j)
                {
                    std::vector<int>& t = threeSumResult[j];
                    std::vector<int> v(4, 0);
                    v[0] = nums[i];
                    v[1] = t[0];
                    v[2] = t[1];
                    v[3] = t[2];

                    result.push_back(v);
                }

                threeSumResult.clear();
            }

            while (i+1 < count && nums[i] == nums[i+1]) ++i;
        }

        return result;
    }

    static void PrintVector (const std::vector<std::vector<int> >& result)
    {
        printf("[");
        for (int i= 0; i< result.size(); ++i)
        {
            const std::vector<int>& v = result[i];
            printf("[");
            for (int j= 0; j< v.size(); ++j)
            {
                printf("%d, ", v[j]);
            }
            printf("], ");
        }

        printf("]\n");
    }

private:
    void _threeSum (std::vector<int>& nums, std::vector<std::vector<int> >& threeSumResult, int startIndex, int target)
    {
        int count = nums.size();

        for (int i= startIndex; i< count; ++i)
        {
            int tempTarget = target - nums[i];
            int low = i + 1;
            int high = count - 1;

            while (low < high)
            {
                int sum = nums[low] + nums[high];
                if (sum < tempTarget)
                {
                    ++low;
                }
                else if (sum > tempTarget)
                {
                    --high;
                }
                else
                {
                    std::vector<int> v(3, 0);
                    v[0] = nums[i];
                    v[1] = nums[low];
                    v[2] = nums[high];
                    threeSumResult.push_back(v);

                    // 下面这两行分别是v[1], v[2]越过相同项
                    while (low < high && nums[low] == v[1]) ++low;
                    while (low < high && nums[high] == v[2]) --high;
                }
            }

            // 下面这行是v[0]越过相同项，注意最上面for()循环体内还有一个++i
            while (i+1 < count && nums[i] == nums[i+1]) ++i;
        }
    }
};

void test (int data[], int count,  int target)
{
    std::vector<int> nums;
    for (int i=  0; i< count; ++i)
    {
        nums.push_back(data[i]);
    }

    Solution processor;
    std::vector<std::vector<int> > result = processor.fourSum(nums, target);
    Solution::PrintVector(result);
}

int main ()
{

    int a[] = {1, 0, -1, 0, -2, 2, 3, 5, 1, 4, 6, 2, 4 };
    test (a, sizeof(a)/sizeof(a[0]), 4);

    printf("\n");
}
