#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Given the head of a sorted linked list, 
delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.

eg.
Input: head = [1,1,2]
Output: [1,2]
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Problem83
{
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head, *q = nullptr, *tmp = nullptr;
        
        while (p != nullptr)
        {
            q = p->next;
            while (q && p->val == q->val)
            {
                tmp = q;
                q = q->next;
                delete tmp;
            }
            p->next = q;
            p = q;
        }
        return head;
    }

    void runTest()
    {
        //todo 
    }
};