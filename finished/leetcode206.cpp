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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode* > que;
        ListNode* node = head;
        while(node != nullptr) {
            que.push(node);
            node = node ->next;
        }
        ListNode* fakehread = new ListNode();
        node = fakehread;
        while(!que.empty()) {
            node ->next = que.top();
            que.pop();
            node = node ->next;
            node ->next = nullptr;
        }
        return fakehread ->next;
    }
};