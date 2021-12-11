#pragma once

#include <iostream>
#include <string>

using namespace std;

class Problem28
{
public:
    int strStr(string haystack, string needle) 
    {
        int n_sz = needle.size();       //needle size
        int h_sz = haystack.size();     //haystack size

        //corner case
        if (n_sz == 0) return 0;
        if (h_sz == 0) return -1;

        // compute tbc and tbn of needle
        // eg. if needle = "aaabaaaa"
        // tbc = {a, b ,a}
        // tbn = {3, 1, 4}
        int r_sz = 0;
        vector<char> tbc = vector<char>(n_sz);  //tbc: target bucket for char
        vector<int> tbn = vector<int>(n_sz);    //tbn: target bucket for number
        tbc[0] = needle[0];
        tbn[0] = 1;
        for (int i = 1; i < n_sz; ++i)
        {
            if (needle[i] == tbc[r_sz])
            {
                tbn[r_sz]++;
            }
            else
            {
                tbc[++r_sz] = needle[i];
                tbn[r_sz]++;
            }
        }
        ++r_sz;
        tbc.resize(r_sz);
        tbn.resize(r_sz);

        //find the next position in needle which has the value equals to needle.at(0)
        int sf = tbn[0];    //sf refers "Second" place has the value equals to "First" char
        for (int i = 1; i < r_sz; ++i)
        {
            if (tbc[i] == tbc[0])
                break;
            sf += tbn[i];
        }
        if (sf == n_sz) sf = 0;   //if no such position, reset "sf" to 0

        int sz = h_sz - n_sz;     //problem size
        int k_last = r_sz - 1;    //last index of vector tbc or tbn
        int i = 0, j = 0, j2 = 0, k = 0, h_ct = 0, n_ct = 0;
        while (i <= sz) //out loop refers to a new search starting from position i
        {
            j = i;  //init j with i, then move j towards to the next value of tbc
            k = 0;  //k controls the progress of tbc, init it with 0 for a new match
            while (haystack[j] == tbc[k])   //the second loop works on each value of tbc
            {
                j2 = j;     //init j2 with j, we use j2 as a probe to find out the last position in a sequence of unique char
                while (++j2 < h_sz && haystack[j] == haystack[j2]);    //use a third loop to find the last position
                h_ct = j2 - j;    //length of unique char seq, eg. "aaaaa" is such a seq has length = 5
                n_ct = tbn[k];    //find the expected char length from tbn
                if (h_ct > n_ct)  //may or maynot, need to dive in
                {
                    if (k == k_last)  //is last, find it!
                    {
                        return i;
                    }
                    if (k == 0)       //is first char, adjust j to right position
                    {
                        j = j2 - n_ct;
                        break;
                    }
                    j = j2;
                    break;            //otherwise use j2
                }
                else if (h_ct < n_ct) //no way to match
                {
                    j = j2;
                    break;            //just use j2
                }
                j = j2;
                k++;
                if (k == r_sz)        //find it!
                {
                    return i;
                }
                if (j == h_sz)        //search to the end, but not found
                {
                    return -1;
                }
            }
            //when second loop done
            if (i == j) ++i;          //if no progress at all, (blocked by the very first char), just inc i by 1
            else
            {
                if (sf > 0 && i + sf < j)   //if we get clogged at a position next to "i + sf"
                {
                    i += sf;          //we know there is a match: haystack.at(i+sf) == haystack.at(i), so try i+sf next time
                }
                else
                {
                    i = j;            //there is no sf, so it's safe to init next search at the farthest position of current loop of search
                }
            }
        }

        return -1;
    }

    void runTest()
    {
        //aaaabaaabaaaaaacd  mississippi
        //aaabaaaa  issip
        string in1 = "aaaabaaabaaaaaacd";
        string in2 = "aaabaaaa";

        int ret = strStr(in1, in2);
        cout << "ret = " << ret << endl;
    }
};