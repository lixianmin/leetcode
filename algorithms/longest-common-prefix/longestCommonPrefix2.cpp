
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
    // this solution is a bit slower than the first one.
    std::string longestCommonPrefix (std::vector<std::string>& strs)
    {
        int count = strs.size();
        if (count == 0)
        {
            return std::string();
        }

        if (count == 1)
        {
            return strs[0];
        }

        std::sort(strs.begin(), strs.end());

        std::string s0 = strs[0];
        std::string sn = strs[count - 1];

        int maxLength = s0.length();
        for (int i= 0; i< maxLength; ++i)
        {
            if (s0[i] != sn[i])
            {
                return s0.substr(0, i);
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
    v.push_back("hell this");
    v.push_back("hel");
    v.push_back("hello ");
    v.push_back("hello world");
    v.push_back("");
    test (v);

    printf("\n");
}
