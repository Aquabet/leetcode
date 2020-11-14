#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* p = head;
        int length = 0;
        while(p != nullptr) {
            p = p -> next;
            length++;
        }
        p = head;
        for(int i = 0; i < length / 2; i++) {
            p = p -> next;
        }
        return p;
    }
};