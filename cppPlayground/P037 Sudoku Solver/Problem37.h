#pragma once

#include <iostream>
#include <vector>

using namespace std;

enum ETYPE
{
	ROW = 0,
	COLUMN = 1,
	BLOCK = 2
};

struct container
{
public:
	//ETYPE type;
	//short index;
	vector<int> rest;
private:
	int end;
public:

	int CanUse(int target)
	{
		for (int i = 0; i < end; ++i)
		{
			if (rest[i] == target) return i;
		}
		return -1;
	}

	void Use(int idx)
	{
		rest[idx] = rest[--end]; 
	}

	void Restore(int target)
	{
		rest[end++] = target;
	}

	int PickOne(int idx)
	{
		if (idx >= end) return -1;
		return rest[idx];
	}

	void Init(vector<int>& exists) 
	{
		rest = vector<int>(9);
		end = 0;
		for (int i = 1; i <= 9; ++i)
		{
			bool find = false;
			for (int j = 0; j < exists.size(); ++j)
			{
				if (exists[j] == i)
				{
					find = true;
					break;
				}
			}
			if (!find)
			{
				rest[end++] = i;
			}
		}
	}
};

class Cell
{
private:
	container& mRow;
	container& mCol;
	container& mBlk;
	int idxA;
	int idxB;
	int idxC;
public:
	bool valid = false;
public:
	void Init(container& row, container& col, container& blk)
	{
		valid = true;

		mRow = row;
		mCol = col;
		mBlk = blk;
	}

	int PickOne(int idx)
	{
		return mRow.PickOne(idx);
	}

	bool CanUse(int target)
	{
		idxA = mRow.CanUse(target);
		idxB = mCol.CanUse(target);
		idxC = mBlk.CanUse(target);
		if (idxA == -1 || idxB == -1 || idxC == -1)
			return false;
		return true;
	}

	void Use()  //be careful
	{
		mRow.Use(idxA);
		mCol.Use(idxB);
		mBlk.Use(idxC);
	}

	void Restore(int target)
	{
		mRow.Restore(target);
		mCol.Restore(target);
		mBlk.Restore(target);
	}

};

class Problem37
{
public:
	void solveSudoku(vector<vector<char>>& board) {

		//build containers
		vector<container> rows = vector<container>(9);
		vector<container> cols = vector<container>(9);
		vector<container> blks = vector<container>(9);

		vector<int> tmp;
		//init contain with row info
		for (int i = 0; i < 9; ++i)
		{
			tmp.clear();
			for (int j = 0; j < 9; ++j)
			{
				int cur = board[i][j] - '0';
				if (cur > 0)  //1-9
				{
					tmp.emplace_back(cur);
				}
			}
			rows[i].Init(tmp);
		}
		//init contain with col info
		for (int i = 0; i < 9; ++i)
		{
			tmp.clear();
			for (int j = 0; j < 9; ++j)
			{
				int cur = board[j][i] - '0';
				if (cur > 0)  //1-9
				{
					tmp.emplace_back(cur);
				}
			}
			cols[i].Init(tmp);
		}
		//init contain with blk info
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				tmp.clear();
				for (int m = 0; m < 3; ++m)
				{
					for (int n = 0; n < 3; ++n)
					{
						int cur = board[i * 3 + m][j * 3 + n] - '0';
						if (cur > 0) 
						{
							tmp.emplace_back(cur);
						}
					}
				}
				blks[i * 3 + j].Init(tmp);
			}
		}
		//create cells
		vector<vector<Cell>> cells = vector<vector<Cell>>(9);
		for (int i = 0; i < 9; ++i)
		{
			cells[i] = vector<Cell>(9);
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] != '.')
				{
					int blkIdx = (i % 3) * 3 + (j % 3);
					cells[i][j].Init(rows[i], cols[j], blks[blkIdx]);
				}
				
			}
		}

		bool ret = routine(cells, board, 0, 0);

		return;
	}

	bool routine(vector<vector<Cell>>& cells, vector<vector<char>>& board, int i, int j)
	{
		if (i >= 9) return true;  //bottom condition
		int nextJ = (j + 1) % 9;
		int nextI = i;
		if (nextJ == 0) nextI++;
		if (board[i][j] != '.')
		{
			return routine(cells, board, nextI, nextJ);
		}

		int tar = 0;
		for (int i = 0; i < 9; ++i)
		{
			tar = cells[i][j].PickOne(i);
			if (tar == -1)
				return false;
			if (cells[i][j].CanUse(tar))
			{
				cells[i][j].Use();
				board[i][j] = '0' + tar;
				if (routine(cells, board, nextI, nextJ))
				{
					return true;
				}
				else
				{
					cells[i][j].Restore(tar);
					board[i][j] = '.';
				}
			}
		}
		return false;
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

		solveSudoku(input);

		cout << "ret = " << endl;
		for (auto& row : input)
		{
			for (auto c : row)
			{
				cout << c << " ";
			}
			cout << endl;
		}

	}
};