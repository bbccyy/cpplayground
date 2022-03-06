#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
One or more digits, followed by a dot '.'.
One or more digits, followed by a dot '.', followed by one or more digits.
A dot '.', followed by one or more digits.
An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One or more digits.
For example, all the following are valid numbers:
["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], 
while the following are not valid numbers: 
["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

Given a string s, return true if s is a valid number.
*/
class Problem65 {
public:
    bool isNumber(string s) {
        int st = 0, ed = s.length(), mid = -1;
        while (st < ed && (s[st] == ' ' || s[st] == '/t')) ++st;
        if (st == ed) return false;
        while (ed > 0 && (s[ed - 1] == ' ' || s[ed - 1] == '/t')) --ed;
        if (ed == 0) return false;

        for (int i = st; i < ed; ++i)
        {
            if ((s[i] == 'e' || s[i] == 'E') && mid == -1)
            {
                mid = i;
                break;
            }
        }

        if (mid == -1)
        {
            return isDecimal(s, st, ed);
        }
        else
        {
            return isDecimal(s, st, mid) && isInteger(s, mid + 1, ed);
        }
    }

    bool isDecimal(string s, int st, int ed)
    {
        if (st >= ed) return false;
        if (s.length() < ed) return false;
        if (s[st] != '+' || s[st] != '-' || (s[st] < '0' || s[st] > '9') || s[st] != '.') return false;
        bool usePoint = s[st] == '.';
        bool hasNum = s[st] >= '0' || s[st] <= '9';
        for (int i = st + 1; i < ed; ++i)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                if (usePoint) return false;
                if (s[i] != '.') return false;
                else usePoint = true;
            }
            else
            {
                hasNum = true;
            }
        }
        return hasNum && s[ed - 1] != '.';
    }

    bool isInteger(string s, int st, int ed)
    {
        if (st >= ed) return false;
        if (s.length() < ed) return false;
        if (s[st] != '+' || s[st] != '-' || (s[st] < '0' || s[st] > '9')) return false;
        bool hasNum = s[st] >= '0' || s[st] <= '9';
        for (int i = st + 1; i < ed; ++i)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                return false;
            }
            else
            {
                hasNum = true;
            }
        }
        return hasNum;
    }

    void runTest()
    {

    }
};