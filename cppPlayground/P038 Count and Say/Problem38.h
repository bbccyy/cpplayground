#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Problem38
{
public:
    string countAndSay(int n) {
        vector<char> tb, tmp;
        tb.emplace_back('1');
        int sz = 0, k = 0;
        char cur = ' ';
        for (int i = 2; i <= n; ++i)
        {
            sz = tb.size();
            for (int j = 0; j < sz;)
            {
                k = j;
                cur = tb[j++];
                while (j < sz && tb[j] == cur) ++j;
                tmp.emplace_back(j - k + '0');
                tmp.emplace_back(cur);
            }
            tb = tmp;
            tmp = vector<char>();
        }
        return string(tb.data(), tb.size());
    }

    void runTest()
    {
        string ret = countAndSay(6);

        cout << "ret = " << ret << endl;
    }
};