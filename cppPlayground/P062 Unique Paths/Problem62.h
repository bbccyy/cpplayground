#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem62 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> tb = vector<vector<int>>(m, vector<int>(n, 1));
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                tb[j][i] = tb[j][i - 1] + tb[j - 1][i];
            }
        }
        return tb[m - 1][n - 1];
    }

    void runTest()
    {
        int ret = uniquePaths(3, 7);

        cout << "ret = " << ret << endl;
    }
};