
// Source : https://leetcode.com/problems/reverse-integer
// Author : lixianmin?live.cn
// Date   : 2017-03-21

/**********************************************************************************
 * Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 * Note:
 * The input is assumed to be a 32-bit signed integer. Your function should return 0
 * when the reversed integer overflows.
**********************************************************************************/

#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int reverse (int x)
    {
        int result = 0;
        while (x != 0)
        {
            int tail = x % 10;
            int candidate = result*10 + tail;
            if ((candidate - tail) / 10 != result)
            {
                return 0;
            }

            result = candidate;
            x = x / 10;
        }

        return result;
    }
};

void test (int x)
{
    Solution processor;
    printf("%d => %d \n", x, processor.reverse(x));
}

int main ()
{
    test (INT_MIN);
    test (-123456789);
    test (1234567898);

    printf("%d, %d\n", -123%10, -123/10);
    printf("\n");
}
