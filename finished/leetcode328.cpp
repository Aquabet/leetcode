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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode();
        ListNode* even = new ListNode();
        ListNode* oddp = odd;
        ListNode* evenp = even;
        ListNode* p = head;
        bool flag = true;
        while(p != nullptr) {
            ListNode* nextp = p->next;
            if(flag) {
                oddp -> next = p;
                oddp = oddp -> next;
                flag = false;
            }
            else {
                evenp -> next = p;
                evenp = evenp -> next;
                flag = true;
            }
            p = nextp;
        }
        evenp -> next = nullptr;
        oddp -> next = even -> next;
        return odd -> next;
    }
};