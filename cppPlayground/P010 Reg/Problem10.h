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

		int arr_sz = arr.size();
		int str_sz = s.length();

		if (arr_sz == 0 || str_sz == 0)
		{
			if (arr_sz == str_sz) return true;
			if (arr_sz == 0) return false;
		}

		int row_sz = str_sz + 1;

		vector<bool> tb = vector<bool>((arr_sz) * (row_sz));
		auto pt = arr[0];
		bool hasMatch = false;
		for (int j = 0; j < row_sz; ++j)
		{
			if (pt.Match(s, 0, j)) {
				tb[j] = true;
				hasMatch = true;
			}
		}

		if (!hasMatch)
			return false;

		int tb_base = 0, tb_cur = 0;
		for (int i = 1; i < arr_sz; ++i)
		{
			auto pt = arr[i];
			tb_base = row_sz * (i-1);
			for (int j = 0; j < row_sz; ++j)
			{
				tb_cur = tb_base + j;
				if (tb[tb_cur])
				{
					if (pt.star)
					{
						tb[tb_cur + row_sz] = true;
					}
					if (j < row_sz)
					{
						for (int k = 1; k < row_sz - j; ++k)
						{
							if (tb[tb_cur + row_sz + k] == false && pt.Match(s, j, j + k))
							{
								tb[tb_cur + row_sz + k] = true;
							}
						}
					}
				}
			}
		}

		bool ret = tb[(arr_sz) * (row_sz)-1];

		return ret;
	}




	void runTest()
	{
		//auto ret = isMatch("aab", "c*a*b");
		auto ret = isMatch("mississippi", "mis*is*ip*.");
		cout << "ret = " << ret << endl;
		//system("pause");
	}
};
