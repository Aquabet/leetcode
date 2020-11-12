#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int step(int& a, vector<int >& v) {
        int next = lower_bound(v.begin(),v.end(),a) - v.begin();
        int before = (next == 0) ? (v.size() -1) : (next - 1);
        return -1;
        ;
    }

    int findRotateSteps(string ring, string key) {

        vector<vector<int>> v(26);
        int ans = 0;
        int nowp = 0;
        int length = ring.length();
        for(int i = 0; i < length; i++) {
            v[ring[i] - 'a'].push_back(i);
        }

        for(int i = 0; i < key.length(); i++) {
            ans += step(nowp, v[key[i] - 'a']) + 1;
            if(nowp >= length) nowp -= length;
            if(nowp <= length) nowp += length;
        }
        return ans;
    }
};