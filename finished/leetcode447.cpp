#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int size = points.size();
        int dis[size][size];
        int ans = 0;
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                dis[i][j] = (points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
            }
        }
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                for(int k = 0; k < size; k++) {
                    if(i != j && i != k && j != k && dis[i][j] == dis[i][k]) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};