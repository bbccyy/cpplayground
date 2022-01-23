#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
Given an m x n matrix, return all elements of the matrix in spiral order.
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
class Problem54
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> output;
		int sz_Row = matrix.size();
		if (sz_Row == 0) return output;
		int sz_Col = matrix[0].size();

		int r_s = 0, r_e = sz_Row - 1;
		int c_s = 0, c_e = sz_Col - 1;

		while (r_s < r_e && c_s < c_e)
		{
			for (int i = c_s; i <= c_e; ++i)
			{
				output.emplace_back(matrix[r_s][i]);
			}
			for (int j = r_s + 1; j <= r_e; ++j)
			{
				output.emplace_back(matrix[j][c_e]);
			}
			for (int i = c_e - 1; i >= c_s; --i)
			{
				output.emplace_back(matrix[r_e][i]);
			}
			for (int j = r_e - 1; j >= r_s + 1; --j)
			{
				output.emplace_back(matrix[j][c_s]);
			}
			++r_s;
			--r_e;
			++c_s;
			--c_e;
		}

		if (r_s == r_e)
		{
			for (int i = c_s; i <= c_e; ++i)
			{
				output.emplace_back(matrix[r_s][i]);
			}
		}
		else if (c_s == c_e)
		{
			for (int j = r_s; j <= r_e; ++j)
			{
				output.emplace_back(matrix[j][c_s]);
			}
		}
		return output;
	}

	void runTest()
	{
		vector<vector<int>> input = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};

		auto ret = spiralOrder(input);

		cout << "ret = [";
		for (auto elem : ret)
		{
			cout << elem << " ";
		}
		cout << "]" << endl;
	}
};