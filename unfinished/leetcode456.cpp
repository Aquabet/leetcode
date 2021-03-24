#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tree[15010 << 2];
    void pushup(int p) {
        tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
    }
    void build(int s, int t, int p, vector<int>& nums) {
        if (s == t) {
            tree[p] = nums[s];
            return;
        }
        int mid = (s + t) >> 1;
        build(s, mid, p << 1, nums);
        build(mid + 1, t, p << 1 | 1, nums);
        pushup(p);
        return;
    }
    int query(int s, int t, int l, int r, int p, vector<int>& nums) {
        if (s <= l && r <= t)
            return tree[p];
        int maxx = -0x7fffffff;
        int mid = (l + r) >> 1;
        if (s <= mid)
            maxx = max(maxx, query(s, t, l, mid, p << 1, nums));
        if (t > mid)
            maxx = max(maxx, query(s, t, mid + 1, r, p << 1 | 1, nums));
        return maxx;
    }
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if(len<3)
            return false;
        nums.insert(nums.begin(), -0x7fffffff);        
        build(1, len, 1, nums);
        int *v = new int[len+2];
        v[1] = 0x7fffffff;
        for (int i = 2; i <= len; ++i)
            v[i] = min(v[i - 1], nums[i - 1]);
        
        int maxx = -0x7fffffff;
        for (int i = 2; i < len ; ++i) {
            if (nums[i] > v[i]) {
                if(nums[i] > v[i] && nums[i] < maxx && v[i] == v[i-1])
                    return true;
                maxx = max (maxx,nums[i]);
                int pos = query(i + 1, len, 1, len, 1, nums);
                if (pos > v[i] && pos < nums[i])
                    return true;
            }
        }
        return false;
    }
};