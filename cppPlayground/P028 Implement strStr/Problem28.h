#pragma once

#include <iostream>
#include <string>

using namespace std;

class Problem28
{
public:
    int strStr(string haystack, string needle) 
    {
        int n_sz = needle.size();
        int h_sz = haystack.size();
        if (n_sz == 0) return 0;
        if (h_sz == 0) return -1;

        // compute tbc and tbn
        int r_sz = 0;
        vector<char> tbc = vector<char>(n_sz);  //tbc: target bucket char
        vector<int> tbn = vector<int>(n_sz);    //tbn: target bucket number
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

        int sz = h_sz - n_sz;
        int i = 0, j = 0, j2 = 0, k = 0, h_ct = 0, n_ct = 0;
        while (i < sz)
        {
            j = i;  //start pos
            k = 0;  //new round of matching from beginning 
            while (haystack[j] == tbc[k])
            {
                j2 = j;
                while (++j2 < h_sz && haystack[j] == haystack[j2]);
                h_ct = j2 - j;
                n_ct = tbn[k];
                if (h_ct > n_ct)  //not match
                {
                    if (k == 0)  //is first char, adjust j to right position
                    {
                        j = j2 - n_ct;
                        break;
                    }
                    if (tbc[k] != tbc[0])  //not associate to first char, use j2
                    {
                        j = j2;
                        break;
                    }
                    break;   //equivalent to first char, use j
                }
                else if (h_ct < n_ct)
                {
                    j = j2;   //no way to match, use j2
                    break;
                }
                j = j2;
                k++;
                if (k == r_sz)  //find it!
                {
                    return i;
                }
                if (j == h_sz)  //search to the end, but not found
                {
                    return -1;
                }
            }
            if (i == j) ++i;
            else i = j;
        }
    }

    void runTest()
    {
        
    }
};