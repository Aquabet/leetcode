#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static const auto _ = []() { ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); return nullptr; }();

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        TreeNode* p = root;
        queue<TreeNode*> bfs;
        string ans;
        if(p == NULL) return ans;
        bfs.push(p);
        while(bfs.empty() == false) {
            TreeNode* front = bfs.front();
            if(front != NULL) {
                bfs.push(front->left);
                bfs.push(front->right);
                ans += to_string(front->val)+',';
            }
            else{
            	ans += "null,";
			}
            bfs.pop();
        }
            ans.resize(ans.size() - 1);
            return ans;
    }

    vector<int> strtoint(string data,int p1) {
        vector<int> ans;
        int flag = 1;
        if(data[p1] == '-') {
            flag = -1;
            p1++;
        }
        ans.push_back(0);
        while(data[p1] !=',' && p1 < data.size()) {
            ans[0] *= 10;
            ans[0] += data[p1] - '0';
            p1++;
        }
        ans[0]*=flag;
        ans.push_back(p1);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0] == 'n'||data.length() == 0) 
	    return nullptr;
        TreeNode* root = new TreeNode(strtoint(data,0)[0]);
        int p = strtoint(data,0)[1]+1;
        int dir = 1;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty() && p < data.length()) {
            if(data[p] == 'n'){
                p += 5;
                TreeNode* rbq = que.front();
                if(dir == 1){
                    dir = 2;
                }
                else{
                    dir = 1;
                    que.pop();
                }
                continue;
            }
            vector<int>ans1 = strtoint(data,p);
            TreeNode* rbq = que.front();
                if(dir == 1){
                    dir = 2;
                    rbq->left = new TreeNode(ans1[0]);
                    que.push(rbq->left);
                }
                else{
                    dir = 1;
                    rbq->right = new TreeNode(ans1[0]);
                    que.push(rbq->right);
                    que.pop();
                }
            p = ans1[1]+1;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));