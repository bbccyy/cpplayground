#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Problem17
{
public:
    vector<string> letterCombinations(string digits) {
        const string tb[] = { "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ret;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            string cur = tb[digits[i] - '0'];
            int sz = ret.size();
            if (sz == 0)
            {
                for (int k = 0; k < cur.size(); ++k)
                {
                    ret.emplace_back(cur.substr(k, 1));
                }
            }
            else
            {
                for (int j = 0; j < sz; ++j)
                {
                    for (int k = 0; k < cur.size(); ++k)
                    {
                        ret.emplace_back(cur[k] + ret[j]);
                    }
                }
                reverse(ret.begin(), ret.end());
                ret.resize(ret.size() - sz);
            }
        }

        return ret;
    }

    void runTest()
    {
        string input = "23";

        auto ret = letterCombinations(input);

        stringstream ss;
        for (auto& str : ret)
        {
            ss << str << ", ";
        }
        string output = ss.str();
        output.resize(output.size() - 2);
        cout << output << endl;
    }
};