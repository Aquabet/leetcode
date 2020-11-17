#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        bool read[R][C];
        memset(read, false, sizeof(read));
        queue<pair<int, int> > bfs;
        pair<int, int> rbq(r0, c0);
        bfs.push(rbq);
        read[rbq.first][rbq.second] = true;
        while(!bfs.empty()) {
            rbq = bfs.front();
            pair<int, int> rbq2;
            if(rbq.first - 1 >= 0) {
                if(!read[rbq.first - 1][rbq.second]) {
                    read[rbq.first - 1][rbq.second] = true;
                    rbq2.first = rbq.first - 1;
                    rbq2.second = rbq.second;
                    bfs.push(rbq2);
                }
            }
            if(rbq.second - 1 >= 0) {
                if(!read[rbq.first][rbq.second - 1]) {
                    read[rbq.first][rbq.second - 1] = true;
                    rbq2.first = rbq.first;
                    rbq2.second = rbq.second - 1;
                    bfs.push(rbq2);
                }
            }
            if(rbq.first + 1 < R) {
                if(!read[rbq.first + 1][rbq.second]) {
                    read[rbq.first + 1][rbq.second] = true;
                    rbq2.first = rbq.first + 1;
                    rbq2.second = rbq.second;
                    bfs.push(rbq2);
                }
            }
            if(rbq.second + 1 < C) {
                if(!read[rbq.first][rbq.second + 1]) {
                    read[rbq.first][rbq.second + 1] = true;
                    rbq2.first = rbq.first;
                    rbq2.second = rbq.second + 1;
                    bfs.push(rbq2);
                }
            }
            ans.push_back({rbq.first, rbq.second});
            bfs.pop();
        }
        return ans;
    }
};