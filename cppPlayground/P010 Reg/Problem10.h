#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Problem10
{
public:
	struct Pt {
		char c = 0;
		vector<char> ca;
		bool arr = false;
		bool wild = false;
		bool star = false;
		Pt(string s, int i, int j)
		{
			while (i < j)
			{
				ca.emplace_back(s[i++]);
			}
			arr = true;
		}
		Pt(char c1, bool w, bool s) : c(c1), wild(w), star(s)
		{
		}
		bool Match(string s, int i, int j)
		{
			if (wild && star) return true;
			if (wild)
			{
				if (i + 1 == j) return true;
				return false;
			}
			if (arr)
			{
				if (ca.size() != j - i) return false;
				for (int p = 0; p < ca.size();)
				{
					if (ca[p++] != s[i++]) return false;
				}
				return true;
			}
			if (star)
			{
				if (i == j) return true;  //match empty
				while (i < j)
				{
					if (s[i++] != c) return false;
				}
				return true;
			}
			if (i + 1 == j && s[i] == c) return true;
			return false;
		}
	};

public:
	vector<Pt> arr;

public:
	void parsePt(string p)
	{
		arr.clear();
		int sz = p.length();
		for (int i = 0; i < sz; )
		{
			int start = i;
			while (i < sz)
			{
				if (p[i] == '.')
				{
					if (start < i)
					{
						if (start + 1 == i)
						{
							Pt tmp = Pt(p[start], false, false);
							arr.emplace_back(tmp);
						}
						else
						{
							Pt tmp = Pt(p, start, i);
							arr.emplace_back(tmp);
						}
					}
					if (i + 1 < sz && p[i + 1] == '*')
					{
						Pt tmp = Pt(0, true, true);
						arr.emplace_back(tmp);
						i += 2;
						break;
					}
					else
					{
						Pt tmp = Pt(0, true, false);
						arr.emplace_back(tmp);
						i += 1;
						break;
					}
				}
				else if (p[i] == '*')
				{
					if (start >= i)
					{
						cout << "error" << endl;
						return;
					}

					if (start < i - 1)
					{
						if (start < i - 2)
						{
							Pt tmp = Pt(p, start, i - 1);
							arr.emplace_back(tmp);
						}
						else
						{
							Pt tmp = Pt(p[start], false, false);
							arr.emplace_back(tmp);
						}
					}

					Pt tmp = Pt(p[i-1], false, true);
					arr.emplace_back(tmp);
					i += 1;
					break;
				}
				else if (i == sz - 1)
				{
					if (start >= i)
					{
						Pt tmp = Pt(p[i], false, false);
						arr.emplace_back(tmp);
					}
					else
					{
						Pt tmp = Pt(p, start, i + 1);
						arr.emplace_back(tmp);
					}
					i += 1;
					break;
				}
				i += 1;
			}
		}
	}
	
	bool isMatch(string s, string p)
	{
		parsePt(p);

		int a = 1;
		return true;
	}


	void runTest()
	{
		isMatch("mississippi", "mis*is*p*.");
	}
};
