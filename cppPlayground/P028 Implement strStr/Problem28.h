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
            while (k < r_sz && haystack[j] == tbc[k])
            {
                j2 = j;
                while (++j2 < sz && haystack[j] == haystack[j2]);
                h_ct = j2 - j;
                n_ct = tbn[k];
                if (h_ct > n_ct)
                {

                }
                else if (h_ct < n_ct)
                {

                }
                j = j2;
                k++;
            }
            
        }
    }

    void runTest()
    {
        
    }
};