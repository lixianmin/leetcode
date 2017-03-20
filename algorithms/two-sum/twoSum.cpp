
// Source : https://oj.leetcode.com/problems/two-sum/
// Author : lixianmin#live.cn
// Date   : 2017-03-20

/**********************************************************************************
*
* Given an array of integers, find two numbers such that they add up to a specific target number.
*
* The function twoSum should return indices of the two numbers such that they add up to the target,
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2)
* are not zero-based.
*
* You may assume that each input would have exactly one solution.
*
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
*
**********************************************************************************/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

// class Solution
// {
// public:
//     std::vector<int> twoSum(std::vector<int>& nums, int target)
//     {
//         const int size = nums.size();
//         for (int i= 0; i<size; ++i)
//         {
//             for (int j= i+1; j<size; ++j)
//             {
//                 if (nums[i] + nums[j] == target)
//                 {
//                     std::vector<int> results;
//                     results.push_back(i);
//                     results.push_back(j);
//                     return results;
//                 }
//             }
//         }

//         return std::vector<int>();
//     }
// };

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> m;

        const int size = nums.size();
        for (int i= 0; i<size; ++i)
        {
            int first  = nums[i];
            int second = target - first;
            std::unordered_map<int, int>::iterator iter = m.find(second);
            if (iter == m.end())
            {
                m[first] = i;
            }
            else
            {
                std::vector<int> results;
                results.push_back(iter->second);
                results.push_back(i);

                return results;

            }
        }

        return std::vector<int>();
    }
};

int main ()
{
    int raw_nums[] = {2, 7, 17, 3, 11, 15};
    std::vector<int> nums(raw_nums, raw_nums + sizeof(raw_nums)/sizeof(raw_nums[0]));

    Solution solution;
    std::vector<int> results = solution.twoSum(nums, 28);

    for (int i= 0; i< results.size(); ++i)
    {
        printf("%d\n", results[i]);
    }
}
