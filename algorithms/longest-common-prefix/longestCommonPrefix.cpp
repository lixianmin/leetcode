
// Source : https://leetcode.com/problems/longest-common-prefix/#/description
// Author : lixianmin?live.cn
// Date   : 2017-03-23

/**********************************************************************************
 * Write a function to find the longest common prefix string amongst an array of strings.
**********************************************************************************/

#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::string longestCommonPrefix (std::vector<std::string>& strs)
    {
        int count = strs.size();
        if (count == 0)
        {
            return std::string();
        }

        std::string s0 = strs[0];
        int maxLength = s0.length();
        for (int i= 0; i< maxLength; ++i)
        {
            char a = s0[i];
            for (int j= 1; j< count; ++j)
            {
                std::string& test = strs[j];
                if (i == test.length() || test[i] != a)
                {
                    return s0.substr(0, i);
                }
            }
        }

        return s0;
    }
};

void test (std::vector<std::string> strs)
{
    Solution processor;
    printf("%s\n", processor.longestCommonPrefix(strs).c_str());
}

int main ()
{
    std::vector<std::string> v;
    v.push_back("hel");
    // v.push_back("hello ");
    // v.push_back("hell this");
    test (v);

    printf("\n");
}
