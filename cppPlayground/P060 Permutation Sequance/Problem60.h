#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

EG:
Input: n = 3, k = 3
Output: "213"

Input: n = 4, k = 9
Output: "2314"

Input: n = 3, k = 1
Output: "123"
*/
class Problem60
{
public:
    string getPermutation(int n, int k) {
        vector<bool> tb = vector<bool>(n, true);
        vector<int> output = vector<int>(n, 0);
        vector<int> lut = vector<int>(n, 1);
        for (int i = 1; i < n; ++i)
        {
            lut[i] = lut[i - 1] * (i + 1);
        }
        for (int i = n - 1; i >= 0; --i)  //start from the heightest position
        {
            int curMin = nextMin(tb, 0);
            while (i > 0 && k > lut[i - 1])
            {
                k -= lut[i - 1];
                curMin = nextMin(tb, curMin);
            }
            output[i] = curMin;
            mark(tb, curMin);
        }
        vector<char> ret;
        for (int i = n - 1; i >= 0; --i)
            ret.emplace_back('0' + output[i]);
        ret.emplace_back('\0');
        return string(ret.data());
    }

    int nextMin(vector<bool>& tb, int curMin)
    {
        for (int i = curMin; i < tb.size(); ++i)
        {
            if (tb[i]) return i + 1;
        }
        return 0;
    }

    void mark(vector<bool>& tb, int idx)
    {
        tb[idx - 1] = false;
    }

    void runTest()
    {
        int n = 3;
        int k = 2;
        string ret = getPermutation(n, k);

        cout << "ret = " << ret << endl;
    }
};