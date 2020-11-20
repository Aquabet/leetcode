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
    static bool cmp(ListNode* a, ListNode* b) {
        return a ->val < b ->val;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head;
        vector<ListNode* > ve;
        ListNode* p = head;
        while(p != nullptr) {
            ve.push_back(p);
            p = p ->next;
        }
        sort(ve.begin(), ve.end(), cmp);
        for(int i = 0; i < ve.size() - 1; i++) {
            ve[i] ->next = ve[i+1];
        }
        ve[ve.size()-1] ->next = nullptr;
        return ve[0];
    }
};