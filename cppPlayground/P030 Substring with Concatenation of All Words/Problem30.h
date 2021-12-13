#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Problem30
{
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_sz = s.size();            //string size
        int l_sz = words.size();        //list size
        int w_sz = words[0].size();     //word size

        unordered_map<string, int> M;   //<word, index>
        int idx = 0, j2 = 0;
        for (auto& str : words)
            if (M.find(str) == M.end()) M[str] = idx++; //assign index to words

        vector<int> t1 = vector<int>(idx);  //value: word's counter
        for (auto& str : words) t1[M[str]]++;
        
        vector<int> t2 = vector<int>(idx);  //runtime buffer

        vector<int> output;                 //return value
        string sub;
        for (int i = 0; i < w_sz; i++)
        {
            for (int j = i; j <= s_sz - l_sz * w_sz; )
            {
                idx = 0;
                j2 = j;
                while (idx < l_sz)
                {
                    sub = s.substr(j2, w_sz);
                    if (M.find(sub) == M.end() || t2[M[sub]]++ == t1[M[sub]])
                        break;
                    idx++;
                    j2 += w_sz;
                }

                if (idx == l_sz)
                {
                    output.emplace_back(j);
                    while (j2 + w_sz <= s_sz && s.substr(j, w_sz) == s.substr(j2, w_sz))
                    {
                        j += w_sz;
                        j2 += w_sz;
                        output.emplace_back(j);
                    }
                }
                j = j2 + w_sz;
                t2.clear();
            }
        }
        return output;
    }

    void runTest()
    {
        
    }
};