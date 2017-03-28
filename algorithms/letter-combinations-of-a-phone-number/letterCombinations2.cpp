
// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : lixianmin?live.cn
// Date   : 2017-03-27

/**********************************************************************************
 * Given a digit string, return all possible letter combinations that the number
 * could represent.  A mapping of digit to letters (just like on the telephone
 * buttons) is given below.
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 * Note:
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
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
    std::vector<std::string> letterCombinations (std::string digits)
    {
        const char* letters[] = {NULL, NULL, "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::deque<std::string> q;

        int digitCount = digits.size();
        if (digitCount > 0)
        {
            q.push_back("");
            for (int i= 0; i< digitCount; ++i)
            {
                int digit = digits[i] - '0';
                if (NULL == letters[digit])
                {
                    continue;
                }

                int popCount = q.size();
                for (int j= 0; j< popCount; ++j)
                {
                    std::string& s = q.front();
                    q.pop_front();

                    const char* p = letters[digit];
                    while (*p)
                    {
                        s.push_back(*p);
                        q.push_back(s);
                        s.pop_back();

                        ++p;
                    }
                }
            }
        }

        std::vector<std::string> result(q.begin(), q.end());
        return result;
    }
};

void test (std::string digits)
{
    Solution processor;
    std::vector<std::string> v= processor.letterCombinations(digits);
    for (int i= 0; i<v.size(); ++i)
    {
        printf("%s, \n", v[i].c_str());
    }

    printf("-----\n");
}

int main ()
{
    std::string s = "0123404";
    test (s);

    test ("");
    test ("3");
    printf("\n");
}
