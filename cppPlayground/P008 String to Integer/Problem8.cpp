#include "Problem8.h"
#include <iostream>

int Problem8::myAtoi(string s)
{
	int max_int = (int)0x7fffffff;
	int max_head = max_int / 10;
	int max_tail = max_int % 10;
	int min_int = -max_int - 1;
	int min_head = -(min_int / 10);
	int min_tail = -(min_int % 10);

	int ret = 0;
	int sign = 0;
	int cur = 0;
	bool meetNum = false;
	bool overflow = false;
	for (int i = 0; i < s.length(); ++i)
	{
		char c = s[i];
		
		if (c == ' ' || c == '\t')
		{
			if (meetNum) return ret * sign;
			if (sign != 0) return 0;
		}
		else if (c == '+')
		{
			if (meetNum) return ret * sign;
			else if (sign == 0) sign = 1;
			else return ret * sign;
		}
		else  if (c == '-')
		{
			if (meetNum) return ret * sign;
			else if (sign == 0) sign = -1;
			else return ret * sign;
		}
		else if (c >= '0' && c <= '9')
		{
			if (!meetNum) meetNum = true;
			if (sign == 0) sign = 1;
			cur = c - '0';
			
			if (ret > max_head)
			{
				return sign > 0 ? max_int : min_int;
			}
			if (ret == max_head)
			{
				if (sign > 0)
				{
					if (cur >= max_tail)
						return max_int;
				}
				else
				{
					if (cur >= min_tail)
						return min_int;
				}
			}
			ret = ret * 10 + cur;
		}
		else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			if (meetNum)
				return ret * sign;
			return 0;
		}
		else if (c == '.')
		{
			if (meetNum)
				return ret * sign;
			return 0;
		}
		else
		{
			if (meetNum)
				return ret * sign;
			return 0;
		}
	}

	return ret * sign;
}


void Problem8::runTest()
{
	
	string input = "  -  413";
	int ret = myAtoi(input);

	//printf("input = %s, output = %d", input.c_str(), ret);
	cout << "input = " << input << ", output = " << ret << endl;
	system("pause");
	return;
}