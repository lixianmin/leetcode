
// Source : https://leetcode.com/problems/palindrome-number/
// Author : lixianmin?live.cn
// Date   : 2017-03-21

/**********************************************************************************
 * Determine whether an integer is a palindrome. Do this without extra space.
**********************************************************************************/
/*
 * 这个题比我想的要难一些：
 * 1. 负数全部都认为不是回文数, 非0但是以0结尾的不是回文数
 * 2. 因为刚刚解决过reverse integer问题，所以可以参考这个方案
 * 3. 然而，因为是判断回文数，因此只处理到一半就可以停止判断了，也就是x=12321时，
 *    sum = 123, x = 12，此时就可以开始判断了
 */

#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    bool isPalindrome (int x)
    {
        if (x < 0 || (x!=0 && x%10 == 0))
        {
            return false;
        }

        int sum = 0;
        while (x > sum)
        {
            sum = sum * 10 + x % 10;
            x = x / 10;
        }

        return sum == x || sum/10 == x;
    }
};

int main ()
{
    Solution processor;
    printf ("%d\n", processor.isPalindrome(123454321));
    printf ("%d\n", processor.isPalindrome(123210));
    printf("\n");
}
