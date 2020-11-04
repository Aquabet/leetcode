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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int m = 0;
        while(p -> next != nullptr) {
            m++;
            p = p->next;
        }
        if(m == 0) return nullptr;
        if(m+1 == n) {
            head = head->next;
            return head;
        }
        p = head;
        for(int i = 0;i < m-n; i++) {
            p = p->next;
        }

        p ->next = p->next->next;
        return head;
    }
};