#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int > pq;
        int size = stones.size();
        if(size == 0) return 0;
        for(int i = 0; i < size; i++) {
            pq.push(stones[i]);
        }
        while(pq.size() > 1) {
            int fri = pq.top();
            pq.pop();
            int sec = pq.top();
            pq.pop();
            int res = fri - sec;
            if(res > 0) pq.push(res);
        }
        if(pq.size() == 0) return 0;
        return pq.top();
    }
};