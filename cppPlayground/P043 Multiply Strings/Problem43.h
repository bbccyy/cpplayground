#pragma once

#include <iostream>
#include <string>
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

		vector<char> tb = vector<char>(sz_1 + sz_2);
	}

	void runTest()
	{
		
	}
};