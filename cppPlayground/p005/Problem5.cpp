#include "Problem5.h"

string Problem5::longestPalindrome(string s)
{
	int sz = s.size();
	//map = vector<vector<char>>(sz, vector<char>(sz, 0));
	char map1[1000][1000];
	memset(map1, 0, sizeof(map1));
	dealSub(s, 0, sz - 1, map1);

	return s.substr(row, col - row + 1);
}

bool Problem5::dealSub(string s, int i, int j, char map[1000][1000])
{
	if (i > j) 
		return true;
	if (i == j)
	{
		map[i][j] = 1;
		return true;
	}

	if (map[i][j] != 0)
	{
		return map[i][j] > 0 ? true : false;
	}

	if (s[i] == s[j])
	{
		if (dealSub(s, i + 1, j - 1, map))
		{
			map[i][j] = 1;
			if (j - i + 1 > count)
			{
				count = j - i + 1;
				row = i;
				col = j;
			}
			return true;
		}
	}
	
	map[i][j] = -1;
	dealSub(s, i + 1, j, map);
	dealSub(s, i, j - 1, map);
	
	return false;
}

void Problem5::runTest()
{
	auto str = std::string("aacabdkacaa");

	auto result = longestPalindrome(str);

	//printf("%s",result.c_str());
}