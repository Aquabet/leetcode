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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while(l1 != nullptr || l2 != nullptr) {
            ListNode* minnode;
            if(l1 == nullptr) {
                minnode = l2;
                l2 = l2->next;
            }
            else if(l2 == nullptr) {
                minnode = l1;
                l1 = l1->next;
            }
            else {
                minnode = (l1->val < l2->val ? l1 : l2);
                l1->val < l2->val ? (l1 = l1->next) : (l2 = l2->next);
            }
            p ->next = minnode;
            p = p->next;
        }
        head = head->next;
        return head;
    }
};