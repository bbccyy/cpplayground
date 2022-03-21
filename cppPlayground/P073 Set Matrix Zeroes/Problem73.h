#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
*/
class Problem73
{
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r_sz = matrix.size();
        int c_sz = matrix[0].size();

        int tar_r = -1, tar_c = -1;
        for (int r = 0; r < r_sz; ++r)
        {
            for (int c = 0; c < c_sz; ++c)
            {
                if (matrix[r][c] == 0)
                {
                    if (tar_r == -1)
                    {
                        tar_r = r;
                        tar_c = c;
                    }
                    else
                    {
                        matrix[tar_r][c] = 0;
                        matrix[r][tar_c] = 0;
                    }
                }
            }
        }

        if (tar_r < 0) return;  //no 0 found

        //deal all cols
        for (int c = 0; c < c_sz; ++c)
        {
            if (matrix[tar_r][c] == 0 && c != tar_c)
            {
                for (int r = 0; r < r_sz; ++r) matrix[r][c] = 0;
            }
        }

        //deal all rows
        for (int r = 0; r < r_sz; ++r)
        {
            if (matrix[r][tar_c] == 0 && r != tar_r)
            {
                for (int c = 0; c < c_sz; ++c) matrix[r][c] = 0;
            }
        }

        //deal with the cross 
        for (int c = 0; c < c_sz; ++c) matrix[tar_r][c] = 0;
        for (int r = 0; r < r_sz; ++r) matrix[r][tar_c] = 0;

    }

    void runTest()
    {

    }
};