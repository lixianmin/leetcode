
// Source : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
// Author : lixianmin#live.cn
// Date   : 2017-03-28

/**********************************************************************************
* Given an array of integers that is already sorted in ascending order, find two
* numbers such that they add up to a specific target number.
*
* The function twoSum should return indices of the two numbers such that they add
* up to the target, where index1 must be less than index2. Please note that your
* returned answers (both index1 and index2) are not zero-based.
*
* You may assume that each input would have exactly one solution and you may not
* use the same element twice.
*
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
**********************************************************************************/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum (std::vector<int>& nums, int target)
    {
        std::vector<int> result;
        int count = nums.size();
        if (count >= 2)
        {
            int left = 0, right = count - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum < target)
                {
                    ++left;
                }
                else if (sum > target)
                {
                    --right;
                }
                else
                {
                    result.push_back(left + 1);
                    result.push_back(right + 1);
                    return result;
                }
            }
        }

        return result;
    }
};

void test (int data[], int count, int target)
{
    std::vector<int> nums(data, data + count);

    Solution processor;
    std::vector<int> result = processor.twoSum(nums, target);

    printf("[");
    for (int i= 0; i< result.size(); ++i)
    {
        printf("%d, ", result[i]);
    }
    printf("]\n");
}

int main ()
{
    int raw_nums[] = {2, 7, 11, 15};
    test (raw_nums, sizeof(raw_nums)/sizeof(raw_nums[0]), 22);

    printf("\n");
}
