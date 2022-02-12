#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
*/
class Problem59
{
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> output = vector<vector<int>>(n, vector<int>(n));
        int s = 0, e = n - 1, r = 0, ct = 1;
        while (s <= e)
        {
            for (int i = s; i <= e; ++i)
            {
                output[r][i] = ct++;
            }
            for (int j = r + 1; j <= n - r - 1; ++j)
            {
                output[j][e] = ct++;
            }
            for (int i = e - 1; i >= s; --i)
            {
                output[n - r - 1][i] = ct++;
            }
            for (int j = n - r - 1; j > r; --j)
            {
                output[j][s] = ct++;
            }
            s++;
            e--;
            r++;
        }
        return output;
    }

    void runTest()
    {
        int input = 3;
        auto ret = generateMatrix(input);

        cout << "ret = ";

        for (auto& sub : ret)
        {
            cout << "[";
            for (auto elem : sub)
            {
                cout << elem << " ";
            }
            cout << "]" << endl;
        }
    }
};