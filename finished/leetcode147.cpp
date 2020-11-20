#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return head;
        int size = 0;
        int nowval;
        ListNode* p = head;
        ListNode* finishedp = head;
        ListNode* wait = head ->next;
        while(p != nullptr) {
            size++;
            p = p ->next;
        }
        while(wait != nullptr) {
            ListNode* op = wait;
            wait = wait ->next;
            if(op ->val <= head ->val) {
                ListNode* rbq = head;
                head = op;
                op ->next = rbq;

            }
            else if(op ->val >= finishedp ->val) {
                finishedp ->next = op;
                finishedp = finishedp ->next;
            }
            else {
                p = head;
                while(p != finishedp) {
                    if(p ->val <= op ->val && p ->next ->val >= op ->val) {
                        ListNode* rbq = p ->next;
                        p ->next = op;
                        op -> next = rbq;
                        break;
                    }
                    p = p ->next;
                }
            }
        }
        finishedp ->next = nullptr;
        return head;
    }
};