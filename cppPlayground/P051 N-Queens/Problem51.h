#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem51
{
public:
	vector<vector<string>> output;
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<int> col = vector<int>(n);
		vector<bool> helper = vector<bool>(n);
		NQueensSub(col, helper, 1, col.size());
		
		return output;
	}

	void NQueensSub(vector<int>& col, vector<bool> helper, int curRow, int maxCol)
	{
		if (curRow > maxCol)
		{
			output.emplace_back(dumpResults(col));
			return;
		}
		for (int c = 0; c < maxCol; ++c)
		{
			if (col[c] > 0 || helper[c]) continue;
			col[c] = curRow;
			helper[c] = true;
			shiftRight(helper);
			NQueensSub(col, helper, curRow + 1, maxCol);
			shiftLeft(helper);
			helper[c] = false;
			col[c] = 0;
		}
	}

	vector<string> dumpResults(vector<int>& col)
	{
		vector<string> ret = vector<string>(col.size());
		for (int i = 0; i < col.size(); ++i)
		{
			string str;
			int tar = col[i] - 1;
			for (int j = 0; j < col.size(); ++j)
			{
				if (j = tar) str.append("Q");
				else str.append(".");
			}
			ret[tar] = str;
		}
		return ret;
	}

	void shiftRight(vector<bool>& arr)
	{
		bool carry = arr[arr.size() - 1];
		for (int i = 0; i < arr.size(); ++i)
		{
			if ((carry && arr[i]) || (!carry && !arr[i])) continue;
			arr[i] = carry;
			carry = !carry;
		}
	}

	void shiftLeft(vector<bool>& arr)
	{
		bool carry = arr[0];
		for (int i = arr.size() - 1; i >=0; --i)
		{
			if ((carry && arr[i]) || (!carry && !arr[i])) continue;
			arr[i] = carry;
			carry = !carry;
		}
	}

	void runTest()
	{
		
	}
};
