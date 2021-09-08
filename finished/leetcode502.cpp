#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int size = profits.size();
        int i;
        int ptr = 0;
        vector<pair<int, int > > vp;
        for(i = 0; i < size; i++) {
            vp.push_back({capital[i], profits[i]});
        }
        priority_queue<int> pq;
        sort(vp.begin(), vp.end());
        for(i = 0; i < k; i++) {
            while(vp[ptr].first <= w && ptr < size) {
                pq.push(vp[ptr].second);
                ptr++;
            }
            if(!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};