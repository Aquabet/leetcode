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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        ListNode* p = head;
        int cnt = 0;
        while(p != nullptr) {
            cnt++;
            p = p->next;
        }
        int ptr = 0;
        p = head;
        ListNode* tail;
        int modnum = cnt % k;
        int sumnum = cnt / k;
        if(sumnum != 0) {
            for(int i = 0; i < k; i++) {
                ans[i] = p;
                int r = sumnum - 1;
                while(r > 0) {
                    p = p->next;
                    r--;
                }
                if(modnum != 0) {
                    modnum--;
                    p = p->next;
                }
                tail = p;
                p = p->next;
                tail ->next = nullptr;
            }
        } else {
            for(int i = 0; i < k; i++) {
                if(p != nullptr) {
                    ans[i] = p;
                    tail = p;
                    p = p->next;
                    tail ->next = nullptr;
                }
            }
        }
        return ans;
    }
};