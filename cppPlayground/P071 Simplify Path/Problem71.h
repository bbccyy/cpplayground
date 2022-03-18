#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Given a string path, which is an absolute path (starting with a slash '/') to a file or 
directory in a Unix-style file system, convert it to the simplified canonical path.
In a Unix-style file system, a period '.' refers to the current directory, 
a double period '..' refers to the directory up a level, 
and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. 
For this problem, any other format of periods such as '...' are treated as file/directory names.
The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or 
directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.

eg.
Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.
*/
class Problem71
{
public:
    string simplifyPath(string path) {

    }

    void runTest()
    {

    }
};


/*
EXPLANATION

Create a Stack of String with following condition.
Iterate the loop till you doesn't reaches the end of string.
If you encounter a "/" then ignore it.
Create a temp String & Iterate the while loop till you doesn't find "/" and append it to temp.
Now check if temp == "." , then ignore it.
If temp == ".." then pop the element from the stack if it exists.
If no of the above 2 matches push temp to stack as you find a valid path.
Check out temp string on basis of above conditions till you doesn't find "/".
Now add all stack elements to result as res = "/" + st.top() + res
If res.size() is 0 then return "/" if no directory or file is present.
At last return res.
Input: path = "/../"
Output: "/"
Input: path = "/home//foo/"
Output: "/home/foo"
ALGORITHM

By looking at examples we can see that the above simplification process just behaves like a stack.
Whenever we encounter any file¡¯s name, we simply push it into the stack.
when we come across ¡± . ¡± we do nothing
When we find ¡°..¡± in our path, we simply pop the topmost element as we have to jump back to parent¡¯s directory.
When we see multiple ¡°////¡± we just ignore them as they are equivalent to one single ¡°/¡±.
After iterating through the whole string the elements remaining in the stack is our simplified absolute path.

*/