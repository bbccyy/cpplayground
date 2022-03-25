#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/
class Problem74
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //two binary search!
        int r_sz = matrix.size();
        if (r_sz == 0) return false;  // pointless condition 

        int c_sz = matrix[0].size();

        if (matrix[0][0] > target || matrix[r_sz - 1][c_sz - 1] < target)
            return false;

        int s = 0, e = r_sz - 1, m = 0, tar_row = -1;
        while (s <= e)
        {
            m = s + (e - s) / 2;

            if (matrix[m].front() > target)
            {
                e = m - 1;
            }
            else if (matrix[m].back() < target)
            {
                s = m + 1;
            }
            else
            {
                //find the target row!
                tar_row = m;
                break;
            }
        }
        if (tar_row < 0) tar_row = s;  //this sould not happen! 
        s = 0, e = c_sz - 1;
        while (s <= e)
        {
            m = s + (e - s) / 2;
            if (matrix[tar_row][m] == target) return true;
            if (matrix[tar_row][m] < target)
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }

        return  false;
    }

    bool searchMatrix2(vector<vector<int>>& m, int t) {
        // pointless edge case we still have to consider
        if (!m.size() || !m[0].size()) return false;
        // support variables
        int row, l = 0, r = m.size() - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            // moving l up if needed
            if (m[mid].back() < t) l = mid + 1;
            // moving r down if needed
            else if (m[mid][0] > t) r = mid - 1;
            // we found our row!
            else {
                l = mid;
                break;
            };
        }
        // storing the value of the new found row
        row = l;
        // resetting l and r to run a binary search on the rows
        l = 0;
        r = m[0].size() - 1;
        while (l <= r) {
            mid = (l + r) / 2;
            // moving l up if needed
            if (m[row][mid] < t) l = mid + 1;
            // moving r down if needed
            else if (m[row][mid] > t) r = mid - 1;
            // we found our value!
            else return true;
        }
        return false;
    }

    void runTest()
    {
        //todo 
    }
};

/*

Alright: all the elements are sorted and we need to try and find a specific element, right? That is a no-brainer: we need to go with a binary search approach.

Provided neither the matrix or the rows are empty, since a nice problem like this needs to get burdened by pointless requirements that boil down to the chore of writing an extra line to remove silly edge cases <_<

Now, the relatively tricky part here is that we do not have all of them in a single flat container, but in a matrix. We will actually then want to do 2 binary searches: one to find the row to be searched, one to search it directly.

To do so, I declared 4 variables:

row, meant to store which row will be searched, once we found one;
l, r will store the extremes of our search, initialised to 0 and m.size() - 1, respectively;
mid will store the on going average of l and r.
First round of binary search:

we go on until l < r [note that the first one has to be a strict comparison, unlike for the second search];
at each iteration we will compute mid as (l + r) / 2;
we will then compare and find that if t is bigger than the last element of the row we are checking (m[mid].back() < t), it is time to raise l up to mid + 1 and loop again;
specularly, if t is smaller than the first element of the row we are checking (m[mid][0] > t), it is time to lower r down to mid - 1 and loop again;
finally, if neithere condition is correct, we it means that m[mid][0] <= t && m[mid].back() >= t, which implies we are already checking the right row, so we just assign l = mid and break out of the loop.
Be as it is, once we are done iterating, we will store the value of the correct row to search in row, reset l and r and move on with a similar logic to parse this time on a more traditional way if the element is in the row or not: a match will have us return true.

If we exit the loop without any joy, we return false.

*/