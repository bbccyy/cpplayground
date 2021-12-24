#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Problem39
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return rountine(candidates, target, 0, false);
    }

    vector<vector<int>> rountine(vector<int>& candidates, int target, int start, bool special)
    {
        if (start >= candidates.size() || candidates[start] > target)
            return { };
        if (candidates[start] == target)
        {
            return { {target} };
        }

        vector<vector<int>> ret;

        auto ret1 = rountine(candidates, target - candidates[start], start + 1, false);
        for (int i = 0; i < ret1.size(); ++i)
        {
            ret1[i].emplace_back(candidates[start]);
            ret.emplace_back(ret1[i]);
        }

        auto ret2 = rountine(candidates, target - candidates[start], start, true);
        for (int i = 0; i < ret2.size(); ++i)
        {
            ret2[i].emplace_back(candidates[start]);
            ret.emplace_back(ret2[i]);
        }
        if (!special)
        {
            auto ret3 = rountine(candidates, target, start + 1, false);
            for (int i = 0; i < ret3.size(); ++i)
            {
                ret.emplace_back(ret3[i]);
            }
        }
        
        return ret;
    }

    void runTest()
    {
        vector<int> input = { 2 };

        auto ret = combinationSum(input, 1);

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
