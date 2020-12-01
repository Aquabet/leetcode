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
    int countNodes(TreeNode* root) {
        queue<TreeNode* > BFS;
        TreeNode* rbq;
        if(root == nullptr) return 0;
        int ans = 0;
        BFS.push(root);
        while(!BFS.empty()) {
            rbq = BFS.front();
            if(rbq -> left != nullptr) BFS.push(rbq -> left);
            if(rbq -> right != nullptr) BFS.push(rbq -> right);
            ans++;
            BFS.pop();
        }
        return ans;
    }
};