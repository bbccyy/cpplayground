#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent 
the start and the end of the ith interval and intervals is sorted in ascending order by starti. 
You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and 
intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
*/
class Problem57
{
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		//binary search start point: origin = [[2,5][7,9] ...], new = [3,e] -> find the greatest start point that less or equal than 3, which is [2,5]
		//binary search end point: origin = [... [21,30][31,33]], new = [17, 31] -> find the smallest end point that greater or equals than 31, which is [31,33]
		//merge if necessary 
	}

	void runTest()
	{
		
	}
};