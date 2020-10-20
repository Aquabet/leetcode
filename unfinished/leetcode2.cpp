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
/*leedcode 2*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int flag = 0;
        ListNode *head,*l;
        l = head;
        while(l1->next != nullptr&&l2->next != nullptr){
            ListNode* l = l->next;
            l->val = l1->val + l2->val + flag;
            if(l->val >= 10){
                l->val -= 10;
                flag = 1;
            }
            else{
                flag = 0;
            }
        }
        if(flag==1)
        ListNode(1,l);
        return head;
    }
};