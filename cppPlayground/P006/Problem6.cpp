#include "Problem6.h"


string Problem6::convert(string s, int numRows)
{
	int size = s.length();
	if (numRows == 1 || numRows >= size) return s;
	char *c = new char[size + 1];
	c[size] = '\0';

	int gap = numRows * 2 - 2;
	int index = 0, mid = 0;
	for (int i = 0; i < numRows; i++)
	{
		int gap2 = (numRows - i - 1) * 2;
		for (int j = i; j < size; j += gap)
		{
			c[index++] = s.at(j);
			if (i > 0 && i != numRows - 1)
			{
				mid = j + gap2;
				if (mid < size) c[index++] = s.at(mid);
			}
		}
	}

	return (string)c;
}

void Problem6::testRun()
{
	string input = "PAYPALISHIRING";
	string output = convert(input, 3);

	//printf(output.c_str());
}
