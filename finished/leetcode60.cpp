#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0) return head;
        ListNode* p = head;
        ListNode* tail;
        ListNode* newhead;
        int length = 0;
        while(p != nullptr) {
            p = p -> next;
            length++;
        }
        p = head;
        int flag = length - k;
        if(k % length == 0) return head;
        if(flag < 0) {
            flag = (flag % length) + length;
        }
        while(--flag) {
            p = p -> next;
        }
        newhead = p -> next;
        p -> next = nullptr;
        p = newhead;
        while(p -> next != nullptr) p = p -> next;
        p -> next = head;
        return newhead;
    }
};