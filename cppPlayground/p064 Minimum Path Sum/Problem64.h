#pragma once

#include <iostream>
#include <vector>

using namespace std;


/*
Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

eg:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 ¡ú 3 ¡ú 1 ¡ú 1 ¡ú 1 minimizes the sum.
*/
class Problem64 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r_size = grid.size();
        if (r_size <= 0) return 0;
        int c_size = grid[0].size();

        vector<vector<int>> tb = vector<vector<int>>(r_size, vector<int>(c_size, 0));
        //prepare init state
        int base = 0;
        for (int c = 0; c < c_size; ++c)
        {
            tb[0][c] = base + grid[0][c];
            base = tb[0][c];
        }
        for (int r = 1; r < r_size; ++r)
        {
            tb[r][0] = tb[r - 1][0] + grid[r][0];
        }

        //do gready work
        int best = 0;
        for (int r = 1; r < r_size; ++r)
        {
            for (int c = 1; c < c_size; ++c)
            {
                best = tb[r - 1][c] < tb[r][c - 1] ? tb[r - 1][c] : tb[r][c - 1]; 
                tb[r][c] = grid[r][c] + best;
            }
        }

        return tb[r_size - 1][c_size - 1];
    }

    void runTest()
    {
        //todo 
        vector<vector<int>> input = { {1,2,3},{2,3,4} };

        auto ret = minPathSum(input);

        cout << "ret = " << ret << endl;
    }
};