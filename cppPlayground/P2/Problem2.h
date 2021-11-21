#pragma once
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Problem2
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2);

    void runTest();
};

