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

class Problem24
{
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* preHead = new ListNode(0, head);
        ListNode* p1 = preHead, *p2 = head, *p3 = head->next;
        while (p3 != nullptr)
        {
            ListNode* next = p3->next;
            p2->next = next;
            p3->next = p2;
            p1->next = p3;

            p1 = p2;
            p2 = p1->next;
            if (p2 == nullptr)
                break;
            p3 = p2->next;
        }
        return preHead->next;
    }

    void runTest()
    {
        vector<int> v1 = { 1 ,2 };
        ListNode* n1 = new ListNode(v1[0]), * c1 = n1;
        for (int i = 1; i < v1.size(); ++i)
        {
            c1->next = new ListNode(v1[i]);
            c1 = c1->next;
        }

        auto* ret = swapPairs(n1);

        cout << "ret = ";
        while (ret != nullptr)
        {
            cout << ret->val << " ";
            ret = ret->next;
        }
        cout << endl;
    }
};