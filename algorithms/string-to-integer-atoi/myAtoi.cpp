
// Source : https://leetcode.com/problems/string-to-integer-atoi
// Author : lixianmin?live.cn
// Date   : 2017-03-21

/**********************************************************************************
*
* Implement atoi to convert a string to an integer.
* Hint: Carefully consider all possible input cases. If you want a challenge,
* please do not see below and ask yourself what are the possible input cases.
*
* Notes: It is intended for this problem to be specified vaguely (ie, no given input
* specs). You are responsible to gather all the input requirements up front.
**********************************************************************************/

/*
 * 这个题比我想像的要难得多，主要是边界条件太多了，一开始想像到的边界条件包括：
 * 1. 字符串为空
 * 2. 含有负号，正号开头
 * 3. 字符串中有非法字符，比如k, l, m, n这种
 *
 * 然而，实际上通过测试的函数需要处理的情况要多很多：
 * 1. 忽略前面的空白字符。这个可以认为题意没有说清楚，知道就可以了
 * 2. 溢出。这竟然是最难处理的地方，即使等我知道要处理溢出的事情之后，也提交了好几版
 *    才基本完整的处理好，这包括上溢和下溢，而且乘法与加法都需要处理 --- 这很边界
 */

#include <cstdio>
#include <algorithm>
#include <locale>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int myAtoi (std::string str)
    {
        const int length = str.length();
        if (length == 0)
        {
            return 0;
        }

        int startIndex = 0;
        for (int i= startIndex; i< length; ++i)
        {
            if (std::isspace(str[i]))
            {
                startIndex++;
            }
            else
            {
                break;
            }
        }

        int sign = 1;
        if (str[startIndex] == '-')
        {
            sign = -1;
            startIndex ++;
        }
        else if (str[startIndex] == '+')
        {
            startIndex ++;
        }

        int result = 0;
        for (int i= startIndex; i<length; ++i)
        {
            char a = str[i];
            if (a >= '0' && a <= '9')
            {
                // printf ("%d + %d = %d\n", result * 10, a - '0', result * 10 + a - '0');
                int next = result * 10;
                if (result != next/10)
                {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }

                result = next + (a - '0');
                if (result < 0)
                {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
            }
            else
            {
                break;
            }
        }

        result *= sign;
        return result;
    }
};

int main ()
{
    Solution processor;
    printf ("%d\n", processor.myAtoi("+1345"));
    printf ("%d\n", processor.myAtoi("-134a5"));
    printf ("%d\n", processor.myAtoi("1b34a5"));
    printf ("%d\n", processor.myAtoi(""));
    printf ("%d\n", processor.myAtoi("-"));
    printf ("%d\n", processor.myAtoi("+"));
    printf ("%d\n", processor.myAtoi("   345"));
    printf ("%d\n", processor.myAtoi("  +007"));
    printf ("%d\n", processor.myAtoi("  2147483648"));
    printf ("%d\n", processor.myAtoi("  23432534534534"));
    printf ("%d\n", processor.myAtoi("  -2343253453453"));
    printf ("%d\n", processor.myAtoi("    10522545459"));
    printf("\n");
}
