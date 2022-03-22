#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/
class Problem74
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //two binary search!
        int r_sz = matrix.size();
        int c_sz = matrix[0].size();

        if (matrix[0][0] > target || matrix[r_sz - 1][c_sz - 1] < target)
            return false;

        int s = 0, e = r_sz - 1, m = 0;
        while (s < e)
        {
            m = s + (e - s) / 2;
            if (matrix[m][0] == target) return true;
            if (matrix[m][0] < target)
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }

        int r = e;
        if (r < 0) r = 0;
        s = 0, e = c_sz - 1;
        while (s < e)
        {
            m = s + (e - s) / 2;
            if (matrix[r][m] == target) return true;
            if (matrix[r][m] < target)
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
        if (e < 0) e = 0;

        
        return  matrix[r][e] == target;
    }

    void runTest()
    {
        //todo 
    }
};