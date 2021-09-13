#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int circleGame(vector<vector<int>>& toys, vector<vector<int>>& circles, int r) {
        int toysize = toys.size();
        int cirsize = circles.size();
        bool read[toysize];
        int ans = 0;
        memset(read, 0, sizeof(read));
        for(int i = 0; i < toysize; i++) {
            for(int j = 0; j < cirsize; j++) {
                unsigned long long cendis = (toys[i][0]-circles[j][0])*(toys[i][0]-circles[j][0]) + (toys[i][1] - circles[j][1])*(toys[i][1] - circles[j][1]);
                unsigned long long redis = (r - toys[i][2])*(r - toys[i][2]);
                if(r >= toys[i][2] && cendis <= redis) {
                    ans++;
                    read[i] = true;
                    break;
                }
            }
        }
        return ans;
    }
};