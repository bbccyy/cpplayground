#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Problem40
{
public:
    vector<vector<int>> output;
    vector<int> current;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        routine(candidates, target, 0);
        return output;
    }

    void routine(vector<int>& candiateds, int target, int idx)
    {
        if (idx >= candiateds.size()) return;
        int curElem = candiateds[idx];
        if (target < 0 || curElem > target) return;
        if (candiateds[idx] == target)
        {
            current.emplace_back(curElem);
            output.emplace_back(current);
            current.pop_back();
            return;
        }

        //use current
        current.emplace_back(curElem);
        routine(candiateds, target - curElem, idx + 1);
        current.pop_back();
        //do not use current 
        int i = 1;
        while (idx + i < candiateds.size() && candiateds[idx] == candiateds[idx + i]) ++i;
        routine(candiateds, target, idx + i);
    }

    void runTest()
    {
        vector<int> input = { 1 };
        auto ret = combinationSum2(input, 2);

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