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

class Problem23
{
public:
    vector<ListNode*> min_heap;
    int heap_sz = 0;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        min_heap = vector<ListNode*>(lists.size());
        for (auto* node : lists)
        {
            Add(node);
        }

        ListNode* head = peekMin();
        ListNode* cur = head;

        if (head->next == nullptr) getMin();
        else refreshMin();

        while (getSize() > 0)
        {
            cur->next = peekMin();
            cur = cur->next;
            if (cur->next == nullptr) getMin();
            else refreshMin();
        }

        return head;
    }

    inline int getSize()
    {
        return heap_sz;
    }

    inline ListNode* getMin()
    {
        ListNode* min = min_heap[0];
        min_heap[0] = min_heap[heap_sz - 1];
        min_heap[heap_sz - 1] = nullptr;
        --heap_sz;
        maxHeapify();
        return min;
    }

    inline ListNode* peekMin()
    {
        if (heap_sz > 0)
            return min_heap[0];
        return nullptr;
    }

    inline void refreshMin()
    {
        min_heap[0] = min_heap[0]->next;
        maxHeapify();
    }

    inline void Add(ListNode* node)
    {
        int p = heap_sz++;
        min_heap[p] = node;
        minHeapify();
    }

    void minHeapify()
    {
        int p = heap_sz - 1, r = 0;;
        int p_var = 0;
        while (p > 0)
        {
            r = p % 2 == 0 ? (p - 2) / 2 : (p - 1) / 2;
            if (min_heap[p]->val < min_heap[r]->val)
            {
                auto* tmp = min_heap[p];
                min_heap[p] = min_heap[r];
                min_heap[r] = tmp;
                p = r;
            }
            else
            {
                break;
            }
        }
    }

    void maxHeapify()
    {
        int p = 0, l = 1, r = 2;
        int p_var = 0;
        while (true)
        {
            l = 2 * p + 1;
            r = 2 * p + 2;
            if (l >= heap_sz) 
                break;
            p_var = min_heap[p]->val;
            if (p_var < min_heap[l]->val)
            {
                if (r >= heap_sz || p_var < min_heap[r]->val)
                    break;
                else
                {
                    auto* tmp = min_heap[p];
                    min_heap[p] = min_heap[r];
                    min_heap[r] = tmp;
                    p = r;
                }
            }
            else
            {
                if (r < heap_sz && min_heap[l]->val > min_heap[r]->val)
                {
                    auto* tmp = min_heap[p];
                    min_heap[p] = min_heap[r];
                    min_heap[r] = tmp;
                    p = r;
                }
                else
                {
                    auto* tmp = min_heap[p];
                    min_heap[p] = min_heap[l];
                    min_heap[l] = tmp;
                    p = l;
                }
            }
        }
    }

    void runTest()
    {
        vector<int> v1 = { 1,3,5,7,9 };
        vector<int> v2 = { 1,2,3,4,5,17 };
        vector<int> v3 = { 3,5,5,7,12 };
        ListNode* n1 = new ListNode(v1[0]), * c1 = n1;
        ListNode* n2 = new ListNode(v2[0]), * c2 = n2;
        ListNode* n3 = new ListNode(v3[0]), * c3 = n3;
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
        for (int i = 1; i < v3.size(); ++i)
        {
            c3->next = new ListNode(v3[i]);
            c3 = c3->next;
        }

        vector<ListNode*> input = { n1, n2, n3 };

        auto ret = mergeKLists(input);
        cout << "ret = ";
        while (ret != nullptr)
        {
            cout << ret->val << " ";
            ret = ret->next;
        }

    }
};