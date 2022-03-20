#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

eg.
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/
class Problem72
{
public:
    int minDistance(string word1, string word2) {

    }

    void runTest()
    {

    }
};