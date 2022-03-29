#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

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
        int best_s = 0, best_l = INT_MAX, v_sz = 0;
        int p = 0, q = 0;
        unordered_map<char, int> collections;
        unordered_map<char, int> needhave;
        for (auto v : t)
        {
            if (needhave.find(v) == needhave.end())
            {
                needhave[v] = 1;
            }
            else
            {
                needhave[v] = needhave[v] + 1;
            }
        }
        char cur = ' ', cur2 = ' ';
        int curNeedNum = 0;
        while (q < s_sz)
        {
            cur = s.at(q);
            if (needhave.find(cur) != needhave.end())
            {
                //needed
                curNeedNum = needhave[cur];
                if (collections.find(cur) == collections.end())
                    collections[cur] = 1;
                else collections[cur] = collections[cur] + 1;
                if (collections[cur] <= curNeedNum)
                {
                    ++v_sz;
                    while (v_sz == t_sz && p <= q)
                    {
                        //get a match! cmp & shrink
                        if (best_l > q - p + 1)
                        {
                            best_l = q - p + 1;  //update results
                            best_s = p;
                        }
                        cur2 = s.at(p);
                        //compare char at p
                        if (needhave.find(cur2) != needhave.end()) 
                        {
                            if (collections[cur2] == needhave[cur2])
                            {
                                //if we pop out this p, also need to shrink v_sz
                                --v_sz;
                            }
                            collections[cur2] = collections[cur2] - 1;  //pop out 
                        }
                        ++p;
                    }
                }
            }
            ++q;
        }
        if (best_l == INT_MAX)
        {
            return "";
        }
        return s.substr(best_s, best_l);
    }

    void runTest()
    {

    }
};