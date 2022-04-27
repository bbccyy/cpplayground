#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
Given a rows x cols binary matrix filled with 0's and 1's, 
find the largest rectangle containing only 1's and return its area.

eg.
Input: matrix = [
["1","0","1","0","0"],
["1","0","1","1","1"],
["1","1","1","1","1"],
["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Input: matrix = [["0"]]
Output: 0

Input: matrix = [["1"]]
Output: 1

Constraints:
rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/
class Problem85
{
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int r_sz = matrix.size();
        if (r_sz <= 0) return 0;
        int c_sz = matrix[0].size();
        
        vector<int> tb = vector<int>(c_sz, 0);
        for (int c = 0; c < c_sz; ++c)
            tb[c] = matrix[0][c] == '0' ? 0 : 1;

        int ret = maximalRectangleOnLine(tb);

        for (int r = 1; r < r_sz; ++r)
        {
            for (int c = 0; c < c_sz; ++c)
            {
                if (matrix[r][c] == '1')
                    ++tb[c];
                else
                    tb[c] = 0;
            }
            ret = max(ret, maximalRectangleOnLine(tb));
        }
        
        return ret;
    }

    int maximalRectangleOnLine(vector<int> input)
    {
        //TODO 
        return 0;
    }

    void runTest()
    {

    }
};