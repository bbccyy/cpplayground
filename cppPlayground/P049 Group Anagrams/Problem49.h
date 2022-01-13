#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class Problem49
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> output;
		unordered_map<string, vector<string>> tb;
		vector<int> base;
		auto ss = stringstream();
		for (string s : strs)
		{
			base = vector<int>(26);
			ss = stringstream();
			for (int i = 0; i < s.length(); ++i)
			{
				base[s[i] - 'a']++;
			}
			for (int i = 0; i < 26; ++i)
			{
				if (base[i] > 0)
				{
					ss << (char)(i + 'a') << base[i];
				}
			}
			tb[ss.str()].emplace_back(s);
		}

		for (auto pair : tb)
		{
			output.emplace_back(pair.second);
		}
		return output;
    }

    void runTest()
    {
		vector<string> input = { "eat","tea","tan","ate","nat","bat" };

		auto ret = groupAnagrams(input);

		cout << "ret = \n";
		for (auto arr : ret)
		{
			cout << "[";
			for (string s : arr)
			{
				cout << s << " ";
			}
			cout << "]\n";
		}
    }
};
