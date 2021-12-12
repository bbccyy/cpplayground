#pragma once

#include <iostream>

using namespace std;

class Problem29
{
public:
    int divide(int dividend, int divisor) {
        int maxInt = 0x7FFFFFFF;
        int minInt = -maxInt - 1;
        int halfMin = minInt >> 1;

        if (dividend == minInt && divisor == -1)
            return maxInt;
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;
        if (dividend == 0) return 0;

        int sign = 1;
        if ((dividend > 0 && divisor < 0) ||
            (dividend < 0 && divisor > 0))
        {
            sign = -1;
        }
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;

        int ret = 0;
        int a = dividend, b = divisor;
        while (a <= b)
        {
            if (a == b)
            {
                ret += 1;
                break;
            }
            int add = 1;
            b = b << 1;
            while (a <= b)
            {
                add = add << 1;
                if (b < halfMin) break;
                b = b << 1;
                if (a > b)
                {
                    b = b >> 1;
                    break;
                }
            }
            ret += add;
            a = a - b;
            b = divisor;
        }

        if (sign == -1)
            ret = -ret;

        return ret;
    }

    int divide2(int dividend, int divisor)
    {
        bool isPositive = (dividend > 0 == divisor > 0);
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        if (b == 1) return divisor > 0 ? dividend : dividend == INT_MIN ? INT_MAX : -dividend;
        unsigned int ret = 0;
        short i = 0;
        while (a >= b)
        {
            i = 0;
            while (a >= (b << (1 + i)))
            {
                if ((b << (1 + i)) > (a >> 1))
                {
                    break;
                }
                i++;
            }

            ret += (1 << i);
            a -= (b << i);
        }
        if (ret == (1 << 31) and isPositive)
            return 0x7FFFFFFF;
        return isPositive ? ret : -ret;
    }

    void runTest()
    {
        int input1 = -2147483648;
        int input2 = 2;
        int ret = divide2(input1, input2);

        cout << "ret = " << ret << "; ans = " << input1 / input2 << endl;
    }
};