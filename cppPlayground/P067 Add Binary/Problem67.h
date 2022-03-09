#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <strstream>
#include <algorithm>

using namespace std;

/*
Given two binary strings a and b, return their sum as a binary string.

eg.
Input: a = "11", b = "1"
Output: "100"

Input: a = "1010", b = "1011"
Output: "10101"
*/
class Problem67
{
public:
    string addBinary(string a, string b) {
        strstream ss;
        string dummy;
        string& max = dummy, min = dummy;
        if (a.size() < b.size())
        {
            max = b;
            min = a;
        }
        else {
            max = a;
            min = b;
        }
        int carry = 0, tmp = 0, i = max.size() - 1;
        for (int j = min.size() - 1; j >= 0; --i, --j)
        {
            tmp = (max[i] - '0') + (min[j] - '0') + carry;
            carry = tmp > 1 ? 1 : 0;
            tmp = tmp - carry * 2;
            ss << tmp;
        }
        while (i >= 0)
        {
            tmp = (max[i] - '0') + carry;
            carry = tmp > 1 ? 1 : 0;
            tmp = tmp - carry * 2;
            ss << tmp;
            --i;
        }
        if (carry > 0)
        {
            ss << 1;
        }
        ss << '\0';
        string output = ss.str();
        reverse(output.begin(), output.end());
        return output;
    }

    void runTest()
    {
        string inputA = "1";
        string inputB = "11";

        auto ret = addBinary(inputA, inputB);

        cout << "ret = " << ret << endl;
    }
};