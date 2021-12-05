#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Problem22
{
public:

    vector<string> generateParenthesis(int n) {
        vector<char> stk = vector<char>(n * 2);
        vector<string> ret;
        helper(ret, stk, n, n, 0);

        return ret;
    }

    void helper(vector<string>& ret, vector<char>& lst, int nl, int nr, int p)
    {
        if (nr <= 0)
        {
            ret.emplace_back(string(lst.data(), p));
            return;
        }
        if (nl > 0)
        {
            lst[p] = '(';
            helper(ret, lst, nl - 1, nr, p + 1);
        }
        if (nr > nl)
        {
            lst[p] = ')';
            helper(ret, lst, nl, nr - 1, p + 1);
        }
    }

    // can not handle: "()(())()" 
    vector<string> generateParenthesisWrong(int n) {
        vector<string> ret;
        if (n <= 0) return ret;
        if (n == 1)
        {
            ret.emplace_back("()");
            return ret;
        }

        auto subRet = generateParenthesisWrong(n - 1);
        ret.emplace_back(subRet[0] + "()");
        ret.emplace_back("(" + subRet[0] + ")");
        for (int i = 1; i < subRet.size(); ++i)
        {
            ret.emplace_back(subRet[i] + "()");
            ret.emplace_back("()" + subRet[i]);
            ret.emplace_back("(" + subRet[i] + ")");
        }

        return ret;
    }

    void runTest()
    {
        auto ret = generateParenthesis(4);

        cout << "ret = ";
        for (auto& elem : ret)
        {
            cout << elem << ",";
        }
        cout << endl;
    }
};