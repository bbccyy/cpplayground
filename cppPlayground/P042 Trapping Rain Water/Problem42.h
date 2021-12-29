#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Problem42
{
public:
	int trap(vector<int>& height) {
		
		int ret = 0;
		ret += dealOnePass(height);
		reverse(height);
		ret += dealOnePass(height);
	}

	void reverse(vector<int>& height)
	{
		int sz = height.size();
		int i = 0, j = sz - 1, tmp = 0;
		while (i < j)
		{
			tmp = height[i];
			height[i] = height[j];
			height[j] = tmp;
		}
	}

	int dealOnePass(vector<int>& height)
	{
		int sz = height.size();
		int ret = 0, p = 0;
		for (int q = 1; q < sz; )
		{
			while (q < sz && height[p] < height[q]) ++q;
			p = q - 1;  //find valid left
			while (q < sz && height[p] > height[q]) ++q;
			if (q >= sz) break;
			ret += computeWaterVolume(height, p, q);
		}
		return ret;
	}

	int computeWaterVolume(vector<int>& height, int s, int e)
	{
		int h = min(height[s], height[e]);
		int ret = 0;
		for (int i = s + 1; i < e; ++i)
		{
			ret += h - height[i];
		}
		return ret;
	}

	void runTest()
	{
		
	}
};