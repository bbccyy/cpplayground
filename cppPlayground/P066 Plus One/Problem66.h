#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
You are given a large integer represented as an integer array digits, 
where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.

eg.
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
*/
class Problem66
{
public:
    vector<int> plusOne(vector<int>& digits) {
        int d_size = digits.size();
        if (d_size <= 0)
        {
            digits.emplace_back(1);
            return digits;
        }
        digits[d_size - 1] = digits[d_size - 1] + 1;
        int carry = digits[d_size - 1] / 10;
        digits[d_size - 1] = digits[d_size - 1] % 10;
        for (int i = d_size - 2; i >= 0 && carry > 0; --i)
        {
            digits[i] = digits[i] + carry;
            carry = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
        if (carry > 0)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }

    void runTest()
    {
        vector<int> input = vector<int>{ 9,9,9,9 };

        auto ret = plusOne(input);

        cout << "ret = ";
        for (auto it = ret.begin(); it != ret.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
};
