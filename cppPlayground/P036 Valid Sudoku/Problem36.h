#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem36
{
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> tb = vector<bool>(10);

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                int m = i * 3, n = j * 3;
                tb = vector<bool>(10);
                for (int p = 0; p < 3; ++p)
                {
                    for (int q = 0; q < 3; ++q)
                    {
                        int c = board[m + p][n + q] - '0';
                        if (c > 0)
                        {
                            if (tb[c])
                            {
                                return false;
                            }
                            tb[c] = true;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 9; ++i)
        {
            tb = vector<bool>(10);
            for (int j = 0; j < 9; ++j)
            {
                int c = board[i][j] - '0';
                if (c > 0)
                {
                    if (tb[c])
                    {
                        return false;
                    }
                    tb[c] = true;
                }
            }
        }

        for (int i = 0; i < 9; ++i)
        {
            tb = vector<bool>(10);
            for (int j = 0; j < 9; ++j)
            {
                int c = board[j][i] - '0';
                if (c > 0)
                {
                    if (tb[c])
                    {
                        return false;
                    }
                    tb[c] = true;
                }
            }
        }

        return true;
    }

    void runTest()
    {
        vector<vector<char>> input = {
            vector<char>{'5','3','.','.','7','.','.','.','.'},
            vector<char>{'6','.','.','1','9','5','.','.','.'},
            vector<char>{'.','9','8','.','.','.','.','6','.'},
            vector<char>{'8','.','.','.','6','.','.','.','3'},
            vector<char>{'4','.','.','8','.','3','.','.','1'},
            vector<char>{'7','.','.','.','2','.','.','.','6'},
            vector<char>{'.','6','.','.','.','.','2','8','.'},
            vector<char>{'.','.','.','4','1','9','.','.','5'},
            vector<char>{'.','.','.','.','8','.','.','7','9'}
        };

        bool ret = isValidSudoku(input);

        cout << "ret = " << ret << endl;
    }
};
