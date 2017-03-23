
// Source : https://leetcode.com/problems/longest-palindromic-substring
// Author : lixianmin?live.cn
// Date   : 2017-03-21

/**********************************************************************************
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 * Example:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 * Example:
 * Input: "cbbd"
 * Output: "bb"
**********************************************************************************/
/*
 * 本来觉得是比较傻的解决方案，没想到却是最简单次优的方案了。这个方案官方解释为Expand
 * Around Center
 *
 * 以下是初版实现，部分需要优化，优化后的参考第二版代码
 */

#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::string longestPalindrome (std::string s)
    {
        std::string maxString;
        int count = s.length();
        for (int i= 0; i< count; ++i)
        {
            _GetSubPalidrome(s, i, i, maxString);
            _GetSubPalidrome(s, i-1, i, maxString);
        }

        return maxString;
    }

private:

    void _GetSubPalidrome (const std::string& s, int leftIndex, int rightIndex, std::string& maxString)
    {
        int count = s.length();

        while (leftIndex >= 0 && rightIndex < count && s[leftIndex] == s[rightIndex])
        {
            int currentLength = rightIndex - leftIndex + 1;
            if (currentLength > maxString.length())
            {
                maxString = s.substr(leftIndex, currentLength);
            }

            --leftIndex;
            ++rightIndex;
        }
    }
};

void test (std::string s)
{
    Solution processor;
    printf("%s ==> %s\n", s.c_str(), processor.longestPalindrome(s).c_str());
}

int main ()
{
    test ("31222210");
    test ("123454321");
    test ("babaddaa");
    test ("ba");
    test ("");
    test ("1");
    printf("\n");
}
