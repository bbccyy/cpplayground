#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem51
{
public:
	vector<vector<string>> output;
	vector<bool> helperRight;
	vector<bool> helperLeft;

public:
	vector<vector<string>> solveNQueens(int n) {
		vector<int> col = vector<int>(n);
		helperRight = vector<bool>(n * 2);
		helperLeft = vector<bool>(n * 2);
		NQueensSub(col, 1, col.size());
		
		return output;
	}

	void NQueensSub(vector<int>& col, int curRow, int maxCol)
	{
		if (curRow > maxCol)
		{
			output.emplace_back(dumpResults(col));
			return;
		}
		for (int c = 0; c < maxCol; ++c)
		{
			if (col[c] > 0 || helperRight[c] || helperLeft[c]) continue;
			col[c] = curRow;
			helperRight[c] = true;
			helperLeft[c] = true;
			shiftRight(helperRight);
			shiftLeft(helperLeft);
			NQueensSub(col, curRow + 1, maxCol);
			shiftLeft(helperRight);
			shiftRight(helperLeft);
			helperRight[c] = false;
			helperLeft[c] = false;
			col[c] = 0;
		}
	}

	vector<string> dumpResults(vector<int>& col)
	{
		vector<string> ret = vector<string>(col.size());
		for (int i = 0; i < col.size(); ++i)
		{
			string str;
			int tar = col[i] - 1; //the row index current ret stays
			for (int j = 0; j < col.size(); ++j)
			{
				if (j == i) str.append("Q");
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
		auto ret = solveNQueens(1);

		cout << "ret = " << endl;

		for (auto& lst : ret)
		{
			cout << "Q:" << endl;
			for (auto str : lst)
			{
				cout << str << endl;
			}
		}
	}
};
