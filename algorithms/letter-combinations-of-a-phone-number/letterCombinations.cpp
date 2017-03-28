
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
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<std::string> letterCombinations (std::string digits)
    {
        const char* letters[] = {NULL, NULL, "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<std::string> result = _Combine(digits, 0, digits.length() - 1, letters);
        return result;
    }

private:
    std::vector<std::string> _Combine (std::string& digits, int start, int to, const char* letters[])
    {
        if (start > to)
        {
            return std::vector<std::string>();
        }

        std::vector<std::string> subResult = _Combine(digits, start, to - 1, letters);
        int lastDigit = digits[to] - '0';
        const char* p = letters[lastDigit];

        if (NULL == p)
        {
            return subResult;
        }

        std::vector<std::string> result;
        int subCount = subResult.size();

        if (subCount == 0)
        {
            std::string s;
            while (*p)
            {
                s.push_back(*p);
                result.push_back(s);
                s.pop_back();

                ++p;
            }

            return result;
        }

        for (int i= 0; i< subCount; ++i)
        {
            std::string& s = subResult[i];
            const char* p = letters[lastDigit];

            while (*p)
            {
                s.push_back(*p);
                result.push_back(s);
                s.pop_back();

                ++p;
            }
        }

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
