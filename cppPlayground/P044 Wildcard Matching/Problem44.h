#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Problem44
{
public:
	bool isMatch(string s, string p) {
		int sz_s = s.length();
		int sz_p = p.length();
		if (sz_s == 0 && sz_p == 0) return true;
		if (sz_p == 0) return false;
		if (sz_s == 0)
		{
			for (int i = 0; i < sz_p; ++i)
			{
				if (p[i] != '*')return false;
			}
			return true;
		}

		vector<vector<bool>> tb = vector<vector<bool>>(sz_p);
		for (int i = 0; i <= sz_p; ++i)
		{
			tb[i] = vector<bool>(sz_s);
		}

		bool hasPossible = false;
		for (int j = 0; j < sz_p; ++j)
		{
			hasPossible = false;
			for (int i = 0; i < sz_s; ++i)
			{
				if (j == 0)  //deal first line
				{
					if ((i == 0 && match(p[j], s[i])) ||
						(p[j] == '*'))
					{
						tb[j][i] = true;
						hasPossible = true;
					}
					else
					{
						break;
					}
				}
				else  //for the rest lines
				{
					if (tb[j - 1][i])  //up node is ture
					{
						if (p[j] == '*')
						{
							while (i < sz_s) tb[j][i++] = true;
							hasPossible = true;
							break;
						}
					}

					if (i > 0 && !tb[j][i] && tb[j - 1][i - 1])  //left-up node is true
					{
						tb[j][i] = match(p[j], s[i]);
					}

					if (tb[j][i]) hasPossible = true;
				}
			}
			if (!hasPossible) return false;
		}

		return tb[sz_p - 1][sz_s - 1];
	}

	inline bool match(char a, char b)
	{
		switch (a)
		{
		case '?':
		case '*':
			return true;
		default:
			return a == b;
		}
		return false;
	}

	void runTest()
	{
		
	}
};
