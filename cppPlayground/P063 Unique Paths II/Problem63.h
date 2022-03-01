#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and space is marked as 1 and 0 respectively in the grid.
*/
class Problem63 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r_size = obstacleGrid.size();
        if (r_size <= 0) return 0;
        int c_size = obstacleGrid[0].size();
        bool blocked = false;
        for (int c = 0; c < c_size; ++c)
        {
            if (!blocked && obstacleGrid[0][c] == 0)
                obstacleGrid[0][c] = 1;
            else
            {
                if (!blocked) blocked = true;
                obstacleGrid[0][c] = 0;
            }
        }
        for (int r = 1; r < r_size; ++r)
        {
            for (int c = 0; c < c_size; ++c)
            {
                if (obstacleGrid[r][c] == 1)
                    obstacleGrid[r][c] = 0;
                else
                {
                    if (c > 0 && obstacleGrid[r][c - 1] > 0)
                        obstacleGrid[r][c] += obstacleGrid[r][c - 1];
                    if (obstacleGrid[r-1][c] > 0)
                        obstacleGrid[r][c] += obstacleGrid[r - 1][c];
                }
            }
        }
        return obstacleGrid[r_size - 1][c_size - 1];
    }

    void runTest()
    {
        //todo 
    }
};