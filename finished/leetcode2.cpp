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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        ListNode* head = new ListNode(l1 -> val + l2 -> val);
        if(head -> val >= 10){
            head -> val -= 10;
            flag = 1;
        }
        ListNode* nodep = head;
        while(l1 -> next != nullptr && l2 -> next != nullptr){
            ListNode* l = new ListNode(l1 -> next -> val + l2 -> next -> val + flag);
            nodep -> next = l;
            nodep = nodep -> next;
            if(l -> val >= 10){
                l -> val -= 10;
                flag = 1;
            }
            else{
                flag = 0;
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1 -> next != nullptr || l2 -> next != nullptr){
            ListNode* l = new ListNode(l1 -> next == nullptr ? l2-> next -> val + flag : l1 -> next -> val + flag);
            nodep -> next = l;
            nodep = nodep -> next;
            if(l -> val >= 10){
                l -> val -= 10;
                flag = 1;
            }
            else{
                flag = 0;
            }
            if(l1 -> next != nullptr) l1 = l1 -> next;
            else l2 = l2 -> next;
        }

        if(flag == 1)
        nodep -> next = new ListNode(1);
        return head;
    }
};