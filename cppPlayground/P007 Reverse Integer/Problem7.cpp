#include "Problem7.h"
//#include <stdio.h>

int Problem7::reverse(int x)
{
	//int min_int = -1 << 31;  
	int max_int = 0x7fffffff;
	int min_int = -max_int - 1;

	//printf("min = %d, max = %d", min_int, max_int);

	int min_header = min_int / 10;
	int min_tail = min_int % 10;
	int max_header = max_int / 10;
	int max_tail = max_int % 10;

	if (x < 10 && x > -10)
		return x;

	int ret = 0, tail = 0;
	while (x != 0)
	{
		tail = x % 10;
		x = x / 10;

		if (ret < min_header || (ret == min_header && tail < min_tail))
		{
			return 0;
		}
		if (ret > max_header || (ret == max_header && tail > max_tail))
		{
			return 0;
		}
		ret *= 10;
		ret += tail;
		
	}

	return ret;
}


void Problem7::runTest()
{
	int input = -2147483648;
	int ret = reverse(input);

	//printf("input = %d, reverse = %d", input, ret);

	return;
}