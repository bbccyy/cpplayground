#pragma once

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Problem19
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* probe = head, *target = nullptr;
        --n;
        while (probe->next != nullptr)
        {
            if (n > 0) n--;
            else
            {
                if (target == nullptr) target = head;
                else target = target->next;
            }
            probe = probe->next;
        }
        if (target == nullptr)
        {
            auto ret = head->next;
            delete head;
            return ret;
        }
        if (target->next == probe)
        {
            delete target->next;
            target->next = nullptr;
        }
        else
        {
            auto todel = target->next;
            target->next = todel->next;
            delete todel;
        }
        return head;
    }

    void runTest()
    {
        vector<int> src = { 1,2,3,4,5 };
        ListNode* head = new ListNode(src[0]);
        ListNode* cur = head;
        for (int i = 1; i < src.size(); ++i)
        {
            cur->next = new ListNode(src[i]);
            cur = cur->next;
        }

        ListNode* ret = removeNthFromEnd(head, 1);
        cur = ret;
        stringstream ss;
        while (cur != nullptr)
        {
            ss << cur->val << " ";
            cur = cur->next;
        }

        while (ret != nullptr)
        {
            ListNode* cur = ret->next;
            delete ret;
            ret = cur;
        }

        cout << ss.str() << endl;
    }
};