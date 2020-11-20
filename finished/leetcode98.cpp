#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

long nowval;
bool flag;
class Solution {
public:
    void find(TreeNode* node) {
        if(node ->left != nullptr) {
            find(node ->left);
        }
        if(nowval >= node ->val) {
            flag = false;
        }
        else {
            nowval = node ->val;
        }
        if(node ->right != nullptr) {
            find(node ->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        nowval = (long)INT_MIN - 1;
        flag = true;
        if(root == nullptr) return true;
        find(root);
        return flag;
    }
};