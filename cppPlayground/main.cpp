
#include <stdio.h>
#include <string>
#include <vector>

#include "P010 Reg/Problem10.h"
#include "P011 Contain w most water/Problem11.h"

using namespace std;

int main()
{
    auto sln10 = new Problem10();
	sln10->runTest();

    auto sln11 = new Problem11();
    sln11->runTest();

    return 0;
}