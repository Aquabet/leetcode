#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//前序遍历 根-左-右
class Solution {
public:

    void find(TreeNode* p,vector<int> &ans) {
        ans.push_back(p->val);
        if(p->left != nullptr)
        find(p->left,ans);
        if(p->right != nullptr)
        find(p->right,ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root == nullptr) return v;
        find(root,v);
        return v;
    }
};