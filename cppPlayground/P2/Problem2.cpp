#include "Problem2.h"


ListNode* Problem2::addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0, first, second;
    ListNode* head = new ListNode(0), * tail = head;
    while (l1 || l2 || carry) {
        if (l1) {
            first = l1->val;
            l1 = l1->next;
        }
        else
            first = 0;

        if (l2) {
            second = l2->val;
            l2 = l2->next;
        }
        else
            second = 0;

        int temp = first + second + carry;
        tail->next = new ListNode(temp % 10);
        tail = tail->next;
        carry = temp / 10;

    }
    return head->next;
}

ListNode* Problem2::addTwoNumbers2(ListNode* l1, ListNode* l2) {

    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    ListNode* ret = NULL;
    ListNode* cur = NULL;
    int sum = 0;
    int carry = 0;
    while (l1 != NULL && l2 != NULL)
    {
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        if (ret == NULL)
        {
            ret = new ListNode(sum % 10);
            cur = ret;
        }
        else
        {
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    l2 = l2 == NULL ? l1 : l2;
    while (l2)
    {
        sum = l2->val + carry;
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        l2 = l2->next;
    }

    if (carry != 0)
    {
        ListNode* node = new ListNode(carry);
        cur->next = node;
    }

    return ret;
}

void Problem2::runTest()
{

    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(5);
    ListNode* tmp = new ListNode(6);
    l2->next = tmp;
    tmp->next = new ListNode(4);

    ListNode* ret = addTwoNumbers2(l1, l2);

    printf("val = %d\n", ret->val);
}