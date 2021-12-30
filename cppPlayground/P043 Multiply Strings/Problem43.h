#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Problem43
{
public:
	string multiply(string num1, string num2) {
		if (num1.length() < num2.length())
			return multiplyHandler(num2, num1);
		else
			return multiplyHandler(num1, num2);
	}

	string multiplyHandler(string mulitplicand, string multiplier)
	{
		int sz_1 = mulitplicand.length();
		int sz_2 = multiplier.length();

		if (sz_2 <= 0) return "0";
		if (sz_2 == 1 && multiplier == "0") return "0";
		if (sz_2 == 1 && multiplier == "1") return mulitplicand;

		vector<char> m1 = vector<char>(sz_1);
		for (int i = 0; i < sz_1; ++i)
			m1[i] = mulitplicand[i] - '0';

		vector<char> m2 = vector<char>(sz_2);
		for (int i = 0; i < sz_2; ++i)
			m2[i] = multiplier[i] - '0';

		vector<char> tb = vector<char>(sz_1 + sz_2);
		char carry = 0, cur = 0;
		int t = 0;
		for (int i = sz_2 - 1; i >= 0; --i)
		{
			++t;
			int tb_idx = sz_1 + sz_2 - t;
			for (int j = sz_1 - 1; j >= 0; --j)
			{
				cur = m2[i] * m1[j] + carry + tb[tb_idx];
				carry = cur / 10;
				tb[tb_idx--] = cur % 10;
			}
		}
		int i = 0;
		while (i < (sz_1 + sz_2) && tb[i] == 0) ++i;

		stringstream ss;
		for (; i < (sz_1 + sz_2); ++i)
		{
			ss << char(tb[i] + '0');
		}
		auto ret = ss.str();
		if (ret.length() == 0) return "0";
		return ret;
	}

	void runTest()
	{
		string input1 = "12345";
		string input2 = "234";

		string ret = multiply(input1, input2);

		cout << "ret = " << ret << endl;
	}
};