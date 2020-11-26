#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p = head;
        int sum = 0;
        while(p != nullptr) {
            p = p -> next;
            sum++;
        }
        sum /= 2;
        ListNode* newhead = new ListNode(0,head);
        ListNode* finishp = newhead;
        ListNode* newp = head;
        while(sum--) {
            ListNode* rbq = newp ->next;
            newp ->next = rbq ->next;
            finishp ->next = rbq;
            rbq ->next = newp;
            finishp = newp;
            newp = newp ->next;
        }
        return newhead ->next;
    }
};