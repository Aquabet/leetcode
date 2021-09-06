#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        int size = properties.size();
        int ans = 0;

        int maxDef[size];
        int nowmax = 0;
        memset(maxDef, 0, sizeof(maxDef));
        for(int i = 0; i < size; i++) {
            maxDef[i] = max(properties[i][1], nowmax);
            nowmax = maxDef[i];
        }

        for(int i = 0; i < size; i++) {
            if(properties[i][1] < maxDef[i]) {
                ans++;
            }
        }

        return ans;
    }
};