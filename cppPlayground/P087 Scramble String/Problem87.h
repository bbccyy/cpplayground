#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
We can scramble a string s to get a string t using the following algorithm:
If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, 
i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. 
i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, 
return true if s2 is a scrambled string of s1, otherwise, return false.

Example 1:
Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.

Example 2:
Input: s1 = "abcde", s2 = "caebd"
Output: false

Example 3:
Input: s1 = "a", s2 = "a"
Output: true

Constraints:
s1.length == s2.length
1 <= s1.length <= 30
s1 and s2 consist of lowercase English letters. 
*/

class Problem87
{
public:
    string _s1;
    string _s2;
public:
    bool isScramble(string s1, string s2) {
        _s1 = s1;
        _s2 = s2;
        int sz = s1.length(); 
        if (sz != s2.length())
            return false;

        return isScrambleHelper(s1, 0, sz);
    }

    bool isScrambleHelper(string c, int s, int e)
    {
        string sub = _s2.substr(s, e);
        if (c == sub) return true;
        if (c.size() <= 1) return false;

        for (int i = 1; i < c.size() - 1; ++i)
        {
            //stay
            if (isScrambleHelper(c.substr(0, i), s, s + i))
            {
                if (isScrambleHelper(c.substr(i, c.size()), s + i, e))
                {
                    return true;
                }
            }
            //switch
            if (isScrambleHelper(c.substr(c.size() - i, c.size()), s, s + i))
            {
                if (isScrambleHelper(c.substr(0, c.size() - i), s + i, e))
                {
                    return true;
                }
            }
        }
        return false;
    }

    void runTest()
    {
        string input1 = "abc";
        string input2 = "abc";

        auto ret = isScramble(input1, input2);

        cout << ret << endl;
    }
};