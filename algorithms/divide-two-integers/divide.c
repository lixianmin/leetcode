
// Source : https://leetcode.com/problems/divide-two-integers/
// Author : lixianmin?live.cn
// Date   : 2017-04-13

/**********************************************************************************
 * Divide two integers without using multiplication, division and mod operator.
 *
 * If it is overflow, return MAX_INT.
**********************************************************************************/

#include "basic.h"

typedef long long ll;

int divide (int dividend, int divisor) {
    if (!divisor || (dividend == INT_MIN && divisor == -1)) {
        return INT_MAX;
    }

    ll result = 0;
    ll dvd = abs (dividend);
    ll dvs = abs (divisor);

    while (dvd >= dvs) {
        ll temp = dvs;
        ll multiple = 1;
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        dvd -= temp;
        result += multiple;
    }

    if ((dividend < 0) ^ (divisor < 0)) {
        result = -result;
    }

    return result;
}

void test (int dividend, int divisor) {
    int result = divide (dividend, divisor);
    printf("%d/%d= %d", dividend, divisor, result);
    printf ("----------------------------\n");
}

int main ()
{
    test (13, 5);
    test (-17, 2);

    printf("\n");
}
