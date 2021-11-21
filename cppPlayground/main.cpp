
#include <stdio.h>
#include <string>
#include <vector>

#include "P6/Problem6.h"
#include "P7 Reverse Integer/Problem7.h"

using namespace std;

class Solution {

};

int main()
{
   
    auto sln7 = new Problem7();

    int input = -2147483648;
    int ret = sln7->reverse(input);

    printf("input = %d, reverse = %d", input, ret);

    return 0;
}