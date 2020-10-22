#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<ListNode*> v;
        ListNode* p = head;
        while(p != NULL) {
            v.push_back(p);
            p = p -> next;
        }
        if(v.size() > 1) {
            int backp = v.size()-1;
            int headp = 0;
            while(backp >= headp){
                if(v[backp] -> val != v[headp] -> val)
                return false;
                backp--;
                headp++;
            }
        }
        return true;
    }
};