#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Given a string s consisting of some words separated by some number of spaces, 
return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.
EG:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
*/
class Problem58 {
public:
    int lengthOfLastWord(string s) {
        int p = s.length() - 1;
        while (s.at(p) == ' ') --p;
        int c = 0;
        while (p >= 0 && s.at(p--) != ' ') ++c;
        return c;
    }

    void runTest()
    {
        string input = "a";
        auto ret = lengthOfLastWord(input);

        cout << "ret = " << ret << endl;
    }
};