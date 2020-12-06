#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int ,int > aMap;
        int ans = 0;
        int size = time.size();
        if(size == 0) return 0;
        for(int i = 0; i < 60; i++) {
            aMap.insert(pair<int, int> (i, 0));
        }
        for(int i = 0; i < size; i++) {
            aMap[time[i]%60]++;
        }
        for(int i = 1; i < 30; i++) {
            ans+=aMap[i]*aMap[60-i];
        }
        ans+= aMap[0]*(aMap[0] - 1)/2;//C(^2)(_n)
        ans+= aMap[30]*(aMap[30] - 1)/2;
        return ans;
    }
};