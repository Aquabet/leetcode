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
    void reorderList(ListNode* head) {
        ListNode *node = head;
        int n = 1;
        if(node == nullptr){
            n = 0;
            return;
        }
        else{
            while(node -> next != nullptr){
                n++;
                node = node -> next;
            }
        }
        ListNode newhead = ListNode(head->val);
        ListNode* nodep = &newhead;
        int flag = 1;
        int back = n;
        int fore = 1;
        for(int i = 1;i<n;i++){
            if(flag == 1){
                node = head;
                for(int j = 1;j<back;j++){
                    node = node->next;
                }
                ListNode rbq = ListNode(node->val);
                nodep -> next = &rbq;
                back--;
            }
            if(flag == 0){
                node = head;
                for(int j = 1;j<fore;j++){
                    node = node->next;
                }
                ListNode rbq = ListNode(node->val);
                nodep -> next = &rbq;
                fore++;
            }
        }
        node = head;
        nodep = &newhead;
        for(int i = 1;i<n;i++){
            node->next = nodep->next;
            node = node->next;
            nodep = nodep->next;
        }
    }
};