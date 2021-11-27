#pragma once

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Problem14
{
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz = strs.size();
        if (sz == 0) return 0;
        string base = strs[0];
        int ret = base.length();
        for (int i = 1; i < sz; ++i)
        {
            string cur = strs[i];
            ret = ret > cur.size() ? cur.size() : ret;
            for (int j = 0; j < ret; j++)
            {
                if (cur.at(j) != base.at(j))
                {
                    ret = j;
                    break;
                }
            }
            if (ret == 0) return "";
        }
        return base.substr(0, ret);
    }

    void runTest()
    {
        vector<string> input = { "aba", "abc", "ab" };
        string ret = longestCommonPrefix(input);

        cout << "ret = " << ret;
    }
};