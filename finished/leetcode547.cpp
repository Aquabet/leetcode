#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int findfa(int *fa, int p) {
        if(fa[p] != p) {
            return findfa(fa,fa[p]);
        }
        else {
            return p;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if(n == 0) return 0;
        int fa[n];
        int ans = 0;
        bool read[n];
        memset(read, false, sizeof(read));
        for(int i = 0; i < n; i++) {
            fa[i] = i;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(isConnected[i][j] == 1) {
                    fa[findfa(fa,j)] = findfa(fa,i);//imp
                }
            }
        }
        for(int i = 0; i < n; i++) {
            int thisfa = findfa(fa,i);
            if(read[thisfa] == false) {
                ans++;
                read[thisfa] = true;
            }
        }
        for(int i = 0; i < n; i++) {
            cout<<i+1<<" "<<findfa(fa,i)+1<<endl;
        }
        return ans;
    }
};