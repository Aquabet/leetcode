#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head){
        if(head==nullptr) return;
        vector<ListNode*> v;
        ListNode* node = head;
        v.push_back(head);
        while(node->next!=nullptr){
            v.push_back(node->next);
            node = node->next;
        }
        int flag = 1,phead = 1,pback = v.size()-1;
        node = head;
        for(int i = 1;i<v.size();i++){
            if(flag == 1){
                node->next = v[pback];
                pback--;
                flag = 0;
            }
            else if(flag == 0){
                node->next = v[phead];
                phead++;
                flag = 1;
            }
            node = node->next;
        }
        node->next = nullptr;
    }
};