#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/*
Given an array of strings words and a width maxWidth, 
format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
You should pack your words in a greedy approach; 
that is, pack as many words as you can in each line. 
Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line does not divide evenly between words, 
the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left-justified and no extra space is inserted between words.

Note:
A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.

eg.
Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
*/
class Problem68
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        int w_size = words.size(), idx = 0, gap = 0;
        vector<int> out = vector<int>(3, 0);
        vector<string> ret;
        stringstream ss;
        while (idx < w_size)
        {
            ss.clear();
            ss.str("");
            packOneLine(words, idx, maxWidth, out);
            gap = out[2] - idx;
            if (out[2] + 1 == w_size)
            {
                //end condition is special
                while (idx < out[2])
                {
                    ss << words[idx] << " ";
                    ++idx;
                }
                ss << words[idx];
                ret.emplace_back(ss.str());
                break;
            }
            else
            {
                //common condition
                if (gap == 0)
                {
                    ss << words[idx];
                    for (int i = 0; i < out[0]; ++i)
                        ss << " ";
                }
                else
                {
                    while (idx < out[2])
                    {
                        ss << words[idx];
                        ++idx;
                        for (int i = 0; i < out[0]; ++i)
                            ss << " ";
                        if (out[1] > 0)
                        {
                            ss << " ";
                            --out[1];
                        }
                    }
                    ss << words[idx];
                }
            }
            ++idx;
            ret.emplace_back(ss.str());
        }
        return ret;
    }

    void packOneLine(vector<string>& words, int start, int width, vector<int>& out)
    {
        int ed = start, cost = 0;
        while (ed < words.size())
        {
            cost += words[ed].size();
            if (cost + (ed - start) > width)
            {
                --ed;
                cost -= words[ed].size();
                break;
            }
            ++ed;
        }
        cost = width - cost;    //space cost
        int gaps = ed - start;  //maybe ZERO
        if (gaps == 0)
        {
            out[0] = cost;
            out[1] = 0;
            out[2] = ed;
            return;
        }

        out[0] = cost / gaps;
        out[1] = cost % gaps;
        out[2] = ed;
        return;
    }

    void runTest()
    {

    }
};