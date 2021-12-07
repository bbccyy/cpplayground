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

class Problem25
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 1) 
            return head;

        ListNode* preHead = new ListNode(0, head);
        ListNode* p1 = preHead, * p2 = head, * p3 = nullptr, *tmp = nullptr, *pre = nullptr, *tail = nullptr;
        int ct = k;

        while (p2 != nullptr)
        {
            --ct;
            if (ct == 0)
            {
                ct = k;
                pre = p2->next;
                p3 = p2;
                p2 = p1->next;
                tail = p2;
                while (p2 != p3)
                {
                    tmp = p2->next;
                    p2->next = pre;
                    pre = p2;
                    p2 = tmp;
                }
                p3->next = pre;
                p1->next = p3;
                p2 = tail;
                p1 = p2;
            }
            p2 = p2->next;
        }

        return preHead->next;
    }

    void runTest()
    {
        vector<int> v1 = { 1,3,5,7,9,11,12,21,22,33,35,37,56,99 };
        ListNode* n1 = new ListNode(v1[0]), * c1 = n1;
        for (int i = 1; i < v1.size(); ++i)
        {
            c1->next = new ListNode(v1[i]);
            c1 = c1->next;
        }

        auto* ret = reverseKGroup(n1, 5);
        cout << "ret = ";
        while (ret != nullptr)
        {
            cout << ret->val << " ";
            ret = ret->next;
        }
        cout << endl;
    }
};