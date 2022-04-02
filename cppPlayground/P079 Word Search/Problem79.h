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
    bool exist(vector<vector<char>>& board, string word) {
        //DFS + branch pruning 
    }

    void runTest()
    {
        
    }
};