#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Given an m x n grid of characters board and a string word, 
return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.

Follow up: 
Could you use search pruning to make your solution faster with a larger board?
*/
class Problem79 {
public:
    int r_sz = 0;
    int c_sz = 0;
public:
    bool exist(vector<vector<char>>& board, string word) {
        //DFS + branch pruning 
        r_sz = board.size();
        if (r_sz == 0) return false;
        c_sz = board[0].size();
        vector<vector<bool>> tb = vector<vector<bool>>(r_sz, vector<bool>(c_sz, false));
        for (int r = 0; r < r_sz; ++r)
        {
            for (int c = 0; c < c_sz; ++c)
            {
                if (DFS(board, tb, word, 0, r, c))
                    return true;
            }
        }
        return false;
    }

    bool DFS(vector<vector<char>>& board, vector<vector<bool>>& tb, string& word, int p, int r, int c)
    {
        if (word.length() <= p) return true;
        if (tb[r][c]) return false;
        if (board[r][c] != word.at(p)) return false;

        tb[r][c] = true;
        if (r - 1 >= 0 && DFS(board, tb, word, p + 1, r - 1, c))
        {
            return true;
        }
        if (c - 1 >= 0 && DFS(board, tb, word, p + 1, r, c - 1))
        {
            return true;
        }
        if (r + 1 < r_sz && DFS(board, tb, word, p + 1, r + 1, c))
        {
            return true;
        }
        if (c + 1 < c_sz && DFS(board, tb, word, p + 1, r, c + 1))
        {
            return true;
        }
        tb[r][c] = false;
        return false;
    }

    void runTest()
    {
        
    }
};
