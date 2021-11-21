#pragma once
#include <vector>
#include <string>

using namespace std;

class Problem5
{
public:
	char** table;  //array 2d
	vector<vector<char>> map;
	int row = 0;
	int col = 0;
	int count = 1;

public:
	string longestPalindrome(string s);
	bool dealSub(string s, int i, int j, char map[1000][1000]);

	void runTest();
};

