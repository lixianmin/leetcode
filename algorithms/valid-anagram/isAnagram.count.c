
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

#define COUNT_SIZE (26)

bool isAnagram (char *s, char *t) {
    if (!s && !t) {
        return true;
    }

    int count[COUNT_SIZE]={0};
    for (int i= 0; s[i]; ++i) {
       ++count[s[i]-'a'];
    }

    for (int i= 0; t[i]; ++i) {
        --count[t[i]-'a'];
    }

    for (int i= 0; i< COUNT_SIZE; ++i) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
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
