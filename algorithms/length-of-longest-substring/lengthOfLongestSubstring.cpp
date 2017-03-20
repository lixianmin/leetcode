
// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : lixianmin#live.cn
// Date   : 2017-03-20

/**********************************************************************************
*
* Given a string, find the length of the longest substring without repeating characters.
* Examples:
* Given "abcabcbb", the answer is "abc", which the length is 3.
* Given "bbbbb", the answer is "b", with the length of 1.
* Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must
* be a substring, "pwke" is a subsequence and not a substring.
*
* Subscribe to see which companies asked this question.

**********************************************************************************/

#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int lengthOfLongestSubstring (std::string s)
    {
        std::unordered_map<int, int> m;
        int count = s.length();
        int maxLength = 0;
        int currentLength = 0;
        int startIndex = 0;

        for (int i= 0; i< count; ++i)
        {
            char item = s[i];
            std::unordered_map<int, int>::iterator iter = m.find(item);

            if (iter != m.end())
            {
                int candidateIndex = iter->second + 1;
                startIndex = candidateIndex > startIndex ? candidateIndex : startIndex;
            }

            currentLength = i - startIndex + 1;
            if (currentLength > maxLength)
            {
                maxLength = currentLength;
            }

            m[item] = i;
        }

        return maxLength;
    }
};

int main ()
{
    std::string s = "abcbdeklsjdoifuwerhlzxdkjaiqlwjshdiouweklashasljdiouelkjsdlkjzhksdjhvnweiuac";
    int maxLength = Solution().lengthOfLongestSubstring(s);
    printf("%d", maxLength);

    printf("\n");
}
