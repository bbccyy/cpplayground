#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/
class Problem78
{
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> out;
        for (int k = 0; k <= sz; ++k)
        {
            combination(nums, k, out);
        }
        return out;
    }

    void combination(vector<int>& set, int k, vector<vector<int>>& out)
    {
        vector<int> v;
        helper(set, set.size(), k, out, v);
    }

    void helper(vector<int>& set, int n, int k, vector<vector<int>>& out, vector<int>& cur)
    {
        if (k == 0)
        {
            out.emplace_back(cur);
            return;
        }
        if (n < k) return;

        cur.emplace_back(set[n - 1]);
        helper(set, n - 1, k - 1, out, cur);

        cur.pop_back();
        helper(set, n - 1, k, out, cur);
    }

    void runTest()
    {

    }
};  