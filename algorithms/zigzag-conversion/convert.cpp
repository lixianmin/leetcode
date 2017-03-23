
// Source : https://leetcode.com/problems/zigzag-conversion
// Author : lixianmin?live.cn
// Date   : 2017-03-21

/**********************************************************************************
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of
 * rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
**********************************************************************************/

#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        if (numRows <= 1)
        {
            return s;
        }

        int totalLength = s.length();

        std::string result(totalLength, '0');
        result.clear();

        int lastIndex = -1;
        int factor = 2 * (numRows - 1);

        for (int i= 0; i< numRows; ++i)
        {
            int j = 0;
            while (true)
            {
                int baseIndex = factor * j;
                ++j;

                bool a = _Append(result, s, baseIndex - i, lastIndex);
                bool b = _Append(result, s, baseIndex + i, lastIndex);

                if (!a && !b)
                {
                    break;
                }
           }
        }

        return result;
    }

private:
    bool _Append (std::string& result, const std::string& s, int index, int& lastIndex)
    {
        if (index != lastIndex && index >= 0 && index < s.length())
        {
            result.push_back(s[index]);
            lastIndex = index;
            return true;
        }

        return false;
    }
};

void test (std::string s, int numRows)
{
    Solution processor;
    printf("%s ==> %s\n", s.c_str(), processor.convert(s, numRows).c_str());
}

int main ()
{
    test ("0123456", 2);
    test ("PAYPALISHIRING", 3);
    test ("0123456789", 5);
    test ("AB", 1);
    printf("\n");
}
