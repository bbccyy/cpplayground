#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


/*
Given the head of a linked list and a value x,
partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

eg.
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Input: head = [2,1], x = 2
Output: [1,2]

Constraints:
The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
*/

class Problem86
{
public:
	ListNode* partition(ListNode* head, int x) {
		//corner case
		if (head == nullptr || x < 1) return head;

		//prepare variables
		ListNode *a_h = nullptr, *a, *b_h = nullptr, *b, *p;
		p = head;
		int tar = 0;

		//find x position
		while (--x > 0 && p != nullptr) p = p->next;
		if (p == nullptr) return head;
		else tar = p->val;

		//split to two lists
		p = head;
		while (p != nullptr)
		{
			if (p->val < tar)
			{
				if (a_h == nullptr)
				{
					a_h = p;
					a = p;
				}
				else
				{
					a->next = p;
					a = a->next;
				}
			}
			else
			{
				if (b_h == nullptr)
				{
					b_h = p;
					b = p;
				}
				else
				{
					b->next = p;
					b = b->next;
				}
			}
		}

		//combine and return

	}

	void runTest()
	{

	}
};