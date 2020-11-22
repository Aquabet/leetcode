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
            sum++;
        }
        sum /= 2;
        ListNode* p = head;
        ListNode* fakehead = new ListNode(0, head);
        ListNode* tail = fakehead;
        ListNode* newhead = fakehead;
        while(sum--) {
            newhead = tail ->next ->next ->next;
            ListNode* rbq = tail ->next;
            tail ->next = tail ->next ->next;
            tail ->next ->next = rbq;
            tail = rbq;
            rbq ->next = nullptr;
        }
        head = fakehead ->next;
        delete fakehead;
        return head;
    }
};