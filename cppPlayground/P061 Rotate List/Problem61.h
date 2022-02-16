#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
Given the head of a linked list, rotate the list to the right by k places.

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
*/
class Problem61
{
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int num = 0;
        ListNode *p = head, *e = nullptr;
        while (p != nullptr)
        {
            ++num;
            e = p;
            p = p->next;
        }
        if (num <= 1) return head;
        k = k % num;
        if (k == 0) return head;
        p = head;
        for (int i = 0; i < num - k - 1; ++i)
        {
            p = p->next;
        }
        e->next = head;
        if (p) head = p->next;
        if (p) p->next = nullptr;
        return head;
    }

    void runTest()
    {

    }
};
