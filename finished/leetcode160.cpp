#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode *> stack1;
        stack<ListNode *> stack2;
        ListNode* node1 = headA;
        ListNode* node2 = headB;
        ListNode* lastNode;
        if(headA == headB) return headA;

        while(node1 != NULL) {
            stack1.push(node1);
            node1 = node1 ->next;
        }

        while(node2 != NULL) {
            stack2.push(node2);
            node2 = node2 ->next;
        }

        if(stack1.top() != stack2.top()) {
            return nullptr;
        }

        while(!stack1.empty() && !stack2.empty()) {
            if(stack1.top() == stack2.top()) {
                lastNode = stack1.top();
                stack1.pop();
                stack2.pop();
            } else {
                return lastNode;
            }
        }
        return lastNode;
    }
};