#include<bits/stdc++.h>
using namespace std;

#define LOCAL

#define PB push_back
#define PF push_front

typedef long long ll;
typedef unsigned long long ull;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ll gcd(ll a, ll b) {
    return b?gcd(b,a%b):a;
}

ll exgcd(ll l,ll r,ll &x,ll &y) {
    if(r == 0) {
        x = 1;
        y = 0;
        return l;
    } else {
        ll d = exgcd(r, l%r, y, x);
        y -= l/r*x;
        return d;
    }
}

ll MOD(ll a, ll m) {
    a %= m;
    if(a < 0)a += m;
    return a;
}
//乘法逆元
ll inverse(ll a, ll m) {
    a = MOD(a, m);
    if(a <= 1)return a;
    return MOD((1 - inverse(m, a) * m) / a, m);
}
//快速幂
ll kasumi(ll a, ll b, ll mod) {
    a %= mod;
    if(b < 0)a = inverse(a, mod), b = -b;
    ll ans = 1;
    while(b) {
        if(b & 1)ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans % mod;
}
//二叉树的序列化
string serialize(TreeNode* root) {
        if (!root) {
            return "X";
        }
        auto left = "(" + serialize(root->left) + ")";
        auto right = "(" + serialize(root->right) + ")";
        return left + to_string(root->val) + right;
    }

inline TreeNode* parseSubtree(const string &data, int &ptr) {
    ++ptr; // 跳过左括号
    auto subtree = parse(data, ptr);
    ++ptr; // 跳过右括号
    return subtree;
}

inline int parseInt(const string &data, int &ptr) {
    int x = 0, sgn = 1;
    if (!isdigit(data[ptr])) {
        sgn = -1;
        ++ptr;
    }
    while (isdigit(data[ptr])) {
        x = x * 10 + data[ptr++] - '0';
    }
    return x * sgn;
}

TreeNode* parse(const string &data, int &ptr) {
    if (data[ptr] == 'X') {
        ++ptr;
        return nullptr;
    }
    auto cur = new TreeNode(0);
    cur->left = parseSubtree(data, ptr);
    cur->val = parseInt(data, ptr);
    cur->right = parseSubtree(data, ptr);
    return cur;
}
//二叉树的反序列化
TreeNode* deserialize(string data) {
    int ptr = 0;
    return parse(data, ptr);
}

class Solution {
public:

};

#ifdef LOCAL

int main() {
    freopen("testdata.in", "r", stdin);
}
#endif