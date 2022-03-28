#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every character in t 
(including duplicates) is included in the window. 
If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
A substring is a contiguous sequence of characters within the string.

eg.
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
*/
class Problem76
{
public:
    string minWindow(string s, string t) {
        //sliding window problem
        int s_sz = s.length();
        int t_sz = t.length();

    }

    void runTest()
    {

    }
};