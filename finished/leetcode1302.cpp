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

int maxL = 0;
int ans = 0;
void find(TreeNode* p, int level) {
    if(p->left != nullptr) {
        find(p->left, level+1);
    }
    if(p->right != nullptr) {
        find(p->right, level+1);
    }
    if(level > maxL) {
        ans = p->val;
        maxL = level;
    }
    else if(level == maxL) {
        ans += p->val;
    }
    return;
}
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        ans = 0;
        maxL = 0;
        find(root, 0);
        return ans;
    }
};