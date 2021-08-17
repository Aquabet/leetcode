#include<bits/stdc++.h>
using namespace std;

int cnt[100];
int ranks[100];
bool cmp(int a, int b) {
    if(cnt[a] == cnt[b]) return a < b;
    return cnt[a] < cnt[b];
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int sizem = mat.size();
        int sizen = mat[0].size();

        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < sizem; i++) {
            for(int j = 0; j < sizen; j++) {
                if(mat[i][j] == 1) {
                    cnt[i]++;
                }
            }
        }

        for(int i = 0; i < sizem; i++) {
            ranks[i] = i;
        }
        sort(ranks, ranks + sizem , cmp);
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(ranks[i]);
        }
        return ans;
    }
};