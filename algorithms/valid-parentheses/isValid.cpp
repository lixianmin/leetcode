
// Source : https://leetcode.com/problems/valid-parentheses/
// Author : lixianmin?live.cn
// Date   : 2017-03-22

/**********************************************************************************
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at
 * coordinate (i, ai). n vertical lines are drawn such that the two endpoints of
 * line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms
 * a container, such that the container contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
**********************************************************************************/

#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    bool isValid (std::string s)
    {
        int count = s.length();
        if (count > 0)
        {
            std::vector<char> v;
            for (int i= 0; i< count; ++i)
            {
                switch (s[i])
                {
                case '(':
                    v.push_back('(');
                    break;
                case ')':
                    if (!v.empty() && v.back() == '(')
                    {
                        v.pop_back();
                        break;
                    }
                    return false;
                case '[':
                    v.push_back('[');
                    break;
                case ']':
                    if (!v.empty() && v.back() == '[')
                    {
                        v.pop_back();
                        break;
                    }
                    return false;
                case '{':
                    v.push_back('{');
                    break;
                case '}':
                    if (!v.empty() && v.back() == '{')
                    {
                        v.pop_back();
                        break;
                    }
                    return false;
                }
            }

            return v.empty();
        }

        return true;
    }
};

void test (std::string s)
{
    Solution processor;
    printf("%s => %d\n", s.c_str(), processor.isValid(s));
}

int main ()
{
    test ("[[(())]]");
    test ("[{()}]");
    test ("[(])");
    test ("[");
    test ("[]]");

    printf("\n");
}
