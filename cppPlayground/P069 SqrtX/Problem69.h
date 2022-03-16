#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
Given a non-negative integer x, compute and return the square root of x.
Since the return type is an integer, the decimal digits are truncated, 
and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, 
such as pow(x, 0.5) or x ** 0.5.

hint: y = x^2 - 3   ->   x = sqrt(3), y = 0

eg.
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
*/
class Problem69
{
public:
    int mySqrt(int x) {
        long x0 = x / 2, x_square = x0 * x0;
        if (x == 4) return x0;
        if (x == 0) return 0;
        if (x < 4) return 1;

        while (x_square > x)
        {
            x0 = (x_square + x) / (2 * x0);
            x_square = x0 * x0;
        }

        return x0;
    }

    void runTest()
    {
        int input = 122;

        int ret = mySqrt(input);

        cout << "ret = " << ret << endl;
    }
};