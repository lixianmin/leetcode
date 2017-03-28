
// Source : https://leetcode.com/problems/generate-parentheses/
// Author : lixianmin?live.cn
// Date   : 2017-03-28

/**********************************************************************************
 * Given n pairs of parentheses, write a function to generate all combinations of
 * well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 * [
 *      "((()))",
 *      "(()())",
 *      "(())()",
 *      "()(())",
 *      "()()()"
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
    std::vector<std::string> generateParenthesis (int n)
    {
        std::vector<std::string> result;
        std::string s;
        _Generate(result, s, 0, 0, n);

        return result;
    }

private:
    void _Generate (std::vector<std::string>& result, std::string& s, int open, int close, int n)
    {
        if (open == n && close == n)
        {
            result.push_back(s);
            return;
        }

        if (open < n)
        {
            s.push_back('(');
            _Generate(result, s, open + 1, close, n);
            s.pop_back();
        }

        if (close < open)
        {
            s.push_back(')');
            _Generate(result, s, open, close + 1, n);
            s.pop_back();
        }
    }
};

void test (int n)
{
    Solution processor;
    std::vector<std::string> result = processor.generateParenthesis(n);

    printf("[");
    for (int i= 0; i< result.size(); ++i)
    {
        printf("%s, ", result[i].c_str());
    }

    printf("]\n");
}

int main ()
{
    for (int i= 0; i< 5; ++i)
    {
        test (i);
    }

    printf("\n");
}
