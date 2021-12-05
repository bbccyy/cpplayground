#pragma once

#include <iostream>
#include <vector>

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Problem21
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* head = list1, *cur = nullptr;
        if (head->val > list2->val)
        {
            head = list2;
            list2 = list2->next;
        }
        else 
        {
            list1 = list1->next;
        }
        cur = head;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        ListNode* tail = list1 == nullptr ? list2 : list1;

        while (tail != nullptr)
        {
            cur->next = tail;
            tail = tail->next;
            cur = cur->next;
        }
        cur->next = nullptr;

        return head;
    }

    void runTest()
    {
        vector<int> v1 = { 1,3,5,7,9 };
        vector<int> v2 = { 1,2,3,4,5 };
        ListNode* n1 = new ListNode(v1[0]), *c1 = n1;
        ListNode* n2 = new ListNode(v2[0]), *c2 = n2;
        for (int i = 1; i < v1.size(); ++i)
        {
            c1->next = new ListNode(v1[i]);
            c1 = c1->next;
        }
        for (int i = 1; i < v2.size(); ++i)
        {
            c2->next = new ListNode(v2[i]);
            c2 = c2->next;
        }

        auto ret = mergeTwoLists(n1, n2);
        auto cur = ret;

        cout << "ret = ";
        while (cur != nullptr)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;

        while (ret != nullptr)
        {
            cur = ret;
            ret = ret->next;
            delete cur;
        }
    }
};
