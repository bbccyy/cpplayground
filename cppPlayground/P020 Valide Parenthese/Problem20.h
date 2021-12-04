#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Problem20
{
public:
    bool isValid(string s) {
        char* tb = new char[200]{0};
        tb[(size_t)')'] = '(';
        tb[(size_t)']'] = '[';
        tb[(size_t)'}'] = '{';

        stack<char> stk;
        int sz = s.size();
        for (int i = 0; i < sz; ++i)
        {
            if (stk.empty())
            {
                stk.push(s.at(i));
            }
            else
            {
                if (tb[(size_t)s.at(i)] == 0)
                {
                    stk.push(s.at(i));
                }
                else if(tb[(size_t)s.at(i)] == stk.top())
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        delete []tb;
        tb = nullptr;
        return stk.empty();
    }

    void runTest()
    {
        string input = "()[(]())({[]})";

        bool ret = isValid(input);

        cout << "ret = " << ret << endl;

    }
};