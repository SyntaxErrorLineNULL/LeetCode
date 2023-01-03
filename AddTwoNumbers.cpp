#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto *Result = new ListNode((int) 0);
        int Carry = 0;
        ListNode *Current = Result;
        while(l1 != nullptr || l2 != nullptr){
            int Sum = Carry;
            if(l1)
                // Current->val += l1->val;
                Sum += l1->val;
            if(l2)
                // Current->val += l2->val;
                Sum += l2->val;
            if(Sum >= 10){
                Carry = Sum / 10;
            } else Carry = 0;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            Current->next = new ListNode(Sum % 10);
            Current = Current->next;
        }
        if(Carry)
            Current->next = new ListNode(Carry);
        return Result->next;
        }
};


