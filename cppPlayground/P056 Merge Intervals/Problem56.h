#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/
class Problem56
{
public:
	static bool compare(vector<int>& a, vector<int>& b)
	{
		return a[0] < b[0];
	}

	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int sz = size(intervals);
		if (sz <= 1) return intervals;

		vector<vector<int>> output;
		sort(intervals.begin(), intervals.end(), compare);
		int s = intervals[0][0], e = intervals[0][1]; 
		for (int i = 1; i < sz; ++i)
		{
			auto& cur = intervals[i];
			if (cur[0] > e)  //no interval
			{
				output.emplace_back(vector<int>{s, e});
				s = cur[0];
				e = cur[1];
			}
			else  //has interval
			{
				e = cur[1] > e ? cur[1] : e;  //try refresh the end value 
			}
		}
		output.emplace_back(vector<int>{s, e});

		return output;
	}

	void runTest()
	{
		vector<vector<int>> input = { {1,3},{2,6},{8,10},{15,18} };

		auto ret = merge(input);

		cout << "ret = " << endl;
		for (int i = 0; i < ret.size(); ++i)
		{
			cout << "[";
			for (int j = 0; j < ret[i].size(); ++j)
			{
				cout << ret[i][j] << " ";
			}
			cout << "]" << endl;
		}
	}
};
