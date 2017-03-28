
// Source : https://leetcode.com/problems/count-and-say/
// Author : lixianmin?live.cn
// Date   : 2017-03-24

/**********************************************************************************
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
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
    std::string countAndSay (int n)
    {
        if (n <= 0)
        {
            return std::string();
        }

        std::string s = "1", result = s;
        char strCount[8] = {0};

        for (int x = 1; x < n; ++x)
        {
            s = result;
            result.clear();

            int length = s.length();
            for (int i= 0; i< length; )
            {
                char a = s[i];
                int j = i + 1;

                while (j < length && s[j] == a)
                {
                    ++j;
                }

                sprintf(strCount, "%d", j - i);
                // std::string count = std::to_string(j-i);
                result += strCount;
                result.push_back(a);

                i = j;
            }
        }

        return result;
    }
};

void test (int n)
{
    Solution processor;
    printf("%d -> %s\n", n, processor.countAndSay(n).c_str());
}

int main ()
{
    for (int i= 0; i< 10; ++i)
    {
        test (i);
    }

    printf("\n");
}
