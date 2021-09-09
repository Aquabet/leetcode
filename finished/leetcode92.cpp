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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode* > vec;
        ListNode* p = head;
        while(p != nullptr) {
            vec.push_back(p);
            p = p ->next;
        }

        int size = vec.size();
        int i = left - 1;
        int j = right - 1;

        while(i < j) {
            swap(vec[i], vec[j]);
            i++;
            j--;
        }

        for(int i = 0; i < size - 1; i++) {
            vec[i] ->next = vec[i+1];
        }
        vec[size-1] -> next = nullptr;

        return vec[0];
    }
};