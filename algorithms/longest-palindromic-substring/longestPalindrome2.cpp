
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
        int count = s.length();
        if (count <= 1)
        {
            return s;
        }

        int maxStartIndex = 0;
        int maxLength = 0;

        for (int i= 0; i< count; ++i)
        {
            _GetSubPalidrome(s, i, i, maxStartIndex, maxLength);
            _GetSubPalidrome(s, i-1, i, maxStartIndex, maxLength);
        }

        return s.substr(maxStartIndex, maxLength);
    }

private:

    void _GetSubPalidrome (const std::string& s, int leftIndex, int rightIndex, int& maxStartIndex, int& maxLength)
    {
        int count = s.length();

        while (leftIndex >= 0 && rightIndex < count && s[leftIndex] == s[rightIndex])
        {
            int currentLength = rightIndex - leftIndex + 1;
            if (currentLength > maxLength)
            {
                maxStartIndex = leftIndex;
                maxLength = currentLength;
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
