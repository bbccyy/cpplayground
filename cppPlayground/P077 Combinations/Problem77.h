#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
You may return the answer in any order.

Example 1:
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

Example 2:
Input: n = 1, k = 1
Output: [[1]]

Constraints:
1 <= n <= 20
1 <= k <= n
*/
class Problem77
{
public:
    vector<vector<int>> v;
    vector<char> tb;
public:
    vector<vector<int>> combine(int n, int k) {
        v.clear();
        tb = vector<char>(n + 1, 1);
        vector<int> tmp;
        helper(tmp, n, k);
        return v;
    }

    void helper(vector<int>& cur, int n, int k)
    {
        if (k == 0)
        {
            v.emplace_back(cur);
            return;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (tb[i])
            {
                cur.emplace_back(i);
                tb[i] = 0;
                helper(cur, n, k - 1);
                tb[i] = 1;
                cur.pop_back();
            }
        }
    }

    void runTest()
    {
        auto&& ret = combine(4, 2);

        cout << "ret = [" << endl;
        for (auto v : ret)
        {
            cout << "[";
            for (int i = 0; i < v.size(); ++i)
            {
                if (i != v.size() - 1)
                {
                    cout << v[i] << " ";
                }
                else
                {
                    cout << v[i] << "]" << endl;
                }
            }
        }
        cout << "]" << endl;
    }
};