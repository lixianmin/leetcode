
// Source : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Author : lixianmin?live.cn
// Date   : 2017-04-15

/**********************************************************************************
 * You are given a string, s, and a list of words, words, that are all of the same
 * length. Find all starting indices of substring(s) in s that is a concatenation
 * of each word in words exactly once and without any intervening characters.
 *
 * For example, given:
 * s: "barfoothefoobarman"
 * words: ["foo", "bar"]
 *
 * You should return the indices: [0,9].
 * (order does not matter).
**********************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring (std::string s, std::vector<std::string>& words) {
        const int wordsCount = words.size();
        if (wordsCount == 0) {
            return std::vector<int>();
        }

        const int sLength = s.length();
        const int wordLength = words[0].length();
        int endIndex = sLength - wordsCount * wordLength;
        if (endIndex < 0) {
            return std::vector<int>();
        }

        std::unordered_map<std::string, int> cache;
        std::vector<int> result;

        for (int i= 0; i< wordsCount; ++i) {
            ++cache[words[i]];
        }

        for (int i= 0; i<= endIndex; ++i) {
            std::string t = s.substr (i, wordLength);
            std::unordered_map<std::string, int>::iterator iter = cache.find (t);
            if (iter != cache.end()) {
                -- iter->second;
                for (int j= 1; j< wordsCount; ++j) {
                    int index = i + j*wordLength;
                    t = s.substr(index, wordLength);
                    iter = cache.find (t);
                    if (iter == cache.end()) {
                        break;
                    }

                    --iter->second;
                    if (iter->second < 0) {
                        break;
                    }
                }

                bool isAccept = true;
                for (iter = cache.begin(); iter != cache.end(); ++iter) {
                    if (iter->second != 0) {
                        isAccept = false;
                    }

                    iter->second = 0;
                }

                if (isAccept) {
                    result.push_back(i);
                }

                for (int i= 0; i< wordsCount; ++i) {
                    ++cache[words[i]];
                }
            }
        }

        return result;
    }
};

void test (const std::string& s, std::vector<std::string>& words) {
    Solution processor;
    std::vector<int> result = processor.findSubstring(s, words);

    printf ("[");
    for (int i= 0; i< result.size(); ++i) {
        printf ("%d, ", result[i]);
    }
    printf ("]");
    printf ("----------------------------\n");
}

int main ()
{
    const char* s = "0barfoothefoobarman";
    std::vector<std::string> words;
    words.push_back ("foo");
    words.push_back ("the");
    words.push_back ("bar");
    test (s, words);

    const char* t = "wordgoodgoodgoodbestword";
    words.clear();
    words.push_back("word");
    words.push_back("good");
    words.push_back("best");
    words.push_back("good");
    test (t, words);

    printf("\n");
}
