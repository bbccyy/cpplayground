#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem48
{
public:
    void rotate(vector<vector<int>>& matrix) {
        int sz = matrix.size();
        int tmp = 0;
        for (int i = 0; i < sz; ++i)
        {
            for (int j = i + 1; j < sz; ++j)
            {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        for (int p = 0, q = sz - 1; p < q; ++p, --q)
        {
            for (int i = 0; i < sz; ++i)
            {
                tmp = matrix[i][p];
                matrix[i][p] = matrix[i][q];
                matrix[i][q] = tmp;
            }
        }
    }

    void runTest()
    {

    }
};
