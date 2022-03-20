#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

eg.
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/
class Problem72
{
public:
    vector<vector<int>> tb;  //w1.size by w2.size 
public:
    int minDistance(string word1, string word2) {
        int f_size = word1.size();
        int t_size = word2.size();
        tb = vector<vector<int>>(f_size, vector<int>(t_size, -1));


    }

    int handler(string from, string to, int f_idx, int t_idx, int f_sz, int t_sz)
    {
        //3 bottom condition
        if (f_idx == f_sz && t_idx == t_sz) return 0;  
        if (f_idx == f_sz)
        {
            return t_sz - t_idx;  //all the rest should apply insert ops
        }
        if (t_idx == t_sz)
        {
            return f_sz - f_idx;  //all the rest should apply delete ops
        }

        //in case that we already know about the answer
        if (tb[f_idx][t_idx] > 0)
            return tb[f_idx][t_idx];

        //common case:
        //same at current position
        if (from.at(f_idx) == to.at(t_idx))
        {
            int sub = handler(from, to, f_idx + 1, t_idx + 1, f_sz, t_sz);
            tb[f_idx][t_idx] = sub;
            return sub;
        }
        //not the same
        //insert before f_idx
        int sub_insert = handler(from, to, f_idx, t_idx + 1, f_sz, t_sz);

        //replace at f_idx
        int sub_replace = handler(from, to, f_idx + 1, t_idx + 1, f_sz, t_sz);

        //delete at f_idx
        int sub_delete = handler(from, to, f_idx + 1, t_idx, f_sz, t_sz);

        int best = sub_insert < sub_replace ? sub_insert : sub_replace;
        best = best < sub_delete ? best : sub_delete;
        tb[f_idx][t_idx] = best + 1;

        return tb[f_idx][t_idx];
    }

    void runTest()
    {

    }
};