#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int find(TreeNode*p, int sumnow) {
        sumnow *= 10;
        sumnow += p->val;
        int total = 0;
        if(p->left == nullptr && p->right == nullptr) return sumnow;
        if(p->left != nullptr) total += find(p->left,sumnow);
        if(p->right != nullptr) total += find(p->right,sumnow);
        return total;
    }

    int sumNumbers(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
       return find(root,0);
    }
};