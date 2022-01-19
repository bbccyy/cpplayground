#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Problem52
{
public:
	int totalNQueens(int n) {
		vector<bool> lut_diag = vector<bool>(n * 2, false), lut_anti_diag = vector<bool>(n * 2, false), lut_col = vector<bool>(n, false);
		return queen(lut_col, lut_diag, lut_anti_diag, 0, n);
	}

	int queen(vector<bool>& col, vector<bool>& diag, vector<bool>& anti_diag, int r, int n)
	{
		if (r >= n) return 1;
		int ret = 0;
		for (int c = 0; c < n; ++c)
		{
			if (col[c] || diag[n + c - r] || anti_diag[c + r]) continue;
			col[c] = diag[n + c - r] = anti_diag[c + r] = true;
			ret += queen(col, diag, anti_diag, r + 1, n);
			col[c] = diag[n + c - r] = anti_diag[c + r] = false;
		}
		return ret;
	}

	void runTest()
	{
		auto ret = totalNQueens(4);

		cout << "ret = " << ret << endl;
	}
};
