
// Source : https://leetcode.com/problems/valid-anagram
// Author : lixianmin?live.cn
// Date   : 2017-04-15

/**********************************************************************************
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your solution
 * to such case?
**********************************************************************************/

#include "basic.h"

int comfunc (const void* s, const void* t) {
    return *(char*)s - *(char*)t;
}

bool isAnagram (char *s, char *t) {
    if (!s && !t) {
        return true;
    }

    int lengthS = strlen(s);
    int lengthT = strlen(t);
    if (lengthS != lengthT) {
        return false;
    }

    qsort (s, lengthS, sizeof(char), comfunc);
    qsort (t, lengthT, sizeof(char), comfunc);

    if (strcmp(s, t) == 0) {
        return true;
    }

    return false;
}

void test (char* s, char* t) {
    printf ("---> %s, %s, %d", s, t, isAnagram(s, t));
    printf ("----------------------------\n");
}

int main ()
{
    char s[] = "anagram";
    char t[] = "nagaram";
    test (s, t);

    printf("\n");
}
