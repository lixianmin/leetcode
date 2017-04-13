
// Source : https://leetcode.com/problems/implement-strstr/
// Author : lixianmin?live.cn
// Date   : 2017-04-13

/**********************************************************************************
 * Implement strStr().
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
**********************************************************************************/

#include "basic.h"

int strStr(char* haystack, char* needle)
{
    if (NULL == haystack || NULL == needle)
    {
        return -1;
    }

    if (!*needle)
    {
        return 0;
    }

    const char *head = haystack;
    while (*head)
    {
        const char *h = head, *n = needle;
        while (*n == *h && *n && *h)
        {
            ++n;
            ++h;
        }

        if (!*n)
        {
            return head - haystack;
        }

        ++head;
    }

    return -1;
}

void test (char* haystack, char* needle)
{
    int result = strStr(haystack, needle);
    printf("%s, %s, %d", haystack, needle, result);
    printf ("----------------------------\n");
}

int main ()
{
    test ("hello world", "wor");
    test ("hello world", "test");
    test ("", "");

    printf("\n");
}
