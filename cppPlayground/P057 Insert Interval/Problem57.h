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
    vector<vector<int>> insert2(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> output = vector<vector<int>>(intervals.size() + 1);
        int s = newInterval[0], e = newInterval[1], idx = 0, tarIdx = 0;
        bool flag = true;

        for (size_t i = 0; i < intervals.size(); ++i)
        {
            if (intervals[i][1] < s)
            {
                output[idx++] = intervals[i];
            }
            else if ( intervals[i][0] > e )
            {
                if (flag)
                {
                    flag = false;
                    tarIdx = idx++;
                }
                output[idx++] = intervals[i];
            }
            else
            {
                s = min(intervals[i][0], s);
                e = max(intervals[i][1], e);
                if (flag)
                {
                    flag = false;
                    tarIdx = idx++;
                }
            }
        }
        if (flag)
        {
            output[idx++] = newInterval;
        }
        else
        {
            output[tarIdx] = vector<int>{ s, e };
        }
        output.resize(idx);
        return output;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> result;

        for (size_t i = 0; i < intervals.size(); i++)
        {
            //  the new interval is after the range of other interval, so we can leave the current interval baecause the new one does not overlap with it
            if (intervals[i][1] < newInterval[0])
            {
                result.push_back(intervals[i]);
            }
            // the new interval's range is before the other, so we can add the new interval and update it to the current one
            else if (intervals[i][0] > newInterval[1])
            {
                result.push_back(newInterval);
                newInterval = intervals[i];
            }
            // the new interval is in the range of the other interval, we have an overlap, so we must choose the min for start and max for end of interval 
            else if (intervals[i][1] >= newInterval[0] || intervals[i][0] <= newInterval[1])
            {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                //todo: check the code 
            }
        }

        result.push_back(newInterval);
        return result;
    }

	void runTest()
	{
        //vector<vector<int>> input = { {1,2},{3,5},{6,7},{8,10},{12,16} };
        vector<vector<int>> input = { };
        vector<int> input2 = { 4, 8 };

        auto ret = insert2(input, input2);

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