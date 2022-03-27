#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
Given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

eg.
Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
*/
class Problem75
{
public:
    void sortColors(vector<int>& nums) {
        int i = patition(nums, 0, nums.size() - 1, 0);
        patition(nums, i, nums.size() - 1, 1);
    }

    int patition(vector<int>& nums, int s, int e, int tar)
    {
        while (s <= e)
        {
            if (nums[s] <= tar) ++s;
            else swap(nums, s, e--);
        }
        return s;
    }

    void swap(vector<int>& nums, int a, int b)
    {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }

    void runTest()
    {
        vector<int> input = { 1,1,1,1,1,1,1 };
        //int t = patition(input, 0, input.size() - 1, 2);
        sortColors(input);

        //cout << "ret = " << t << " res = ";
        cout << "ret = ";
        for (auto v : input)
        {
            cout << v << " ";
        }
        cout << endl;
    }
};