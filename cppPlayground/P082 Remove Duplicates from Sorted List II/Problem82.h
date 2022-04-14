#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well.

eg.
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Input: head = [1,1,1,2,3]
Output: [2,3]

Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Problem82
{
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode *q = dummyHead, *p = head;

        while (p != nullptr)
        {
            while (p->next && p->val == p->next->val) p = p->next;
            if (q->next != p)
            {
                // dump p
                ListNode* tmp = nullptr;
                ListNode* todel = q->next;
                p = p->next;
                q->next = p;
                while (todel != tmp)
                {
                    tmp = todel->next;
                    delete todel;
                    todel = tmp;
                }
            }
            else
            {
                q = p;
                p = p->next;
            }
        }

        head = dummyHead->next;
        delete dummyHead;

        return head;
    }

    void runTest()
    {

    }
};