#pragma once
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Problem12 {

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

public:
	string intToRoman(int num)
	{
		stringstream sstream;

		int t[] = { 1000, 500, 100, 50, 10, 5, 1 };
		//char ct[] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
		string ct[] = { "M", "D", "C", "L", "X", "V", "I" };
		int i = 0, header = 0, tail = 0;
		bool even = true;
		while (num > 0)
		{
			even = i % 2 == 0 ? true : false;
			header = num / t[i];
			num = num % t[i];
			while (header-- > 0) sstream << ct[i];
			if (num == 0) break;
			tail = even ? (t[i] * 9 / 10) : (t[i] * 4 / 5);
			if (num >= tail)
			{
				sstream << ct[even ? i + 2 : i + 1] << ct[i];
				num -= tail;
			}
			++i;
		}

		return sstream.str();
	}

	void runTest()
	{
		string ret = intToRoman(3);

		cout << "ret = " << ret << endl;
	}

};