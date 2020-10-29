#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        if(grid[0].size() == 0) return 0;
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    ans += 4;
                    if(i < grid.size() - 1 && j < grid[i].size() - 1) {
                        if(grid[i][j+1] == 1) {
                            ans--;ans--;
                        }
                        if(grid[i+1][j] == 1) {
                            ans--;ans--;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < grid[grid.size() - 1].size()-1; i++) {
            if(grid[grid.size() - 1][i] == 1 && grid[grid.size() - 1][i+1] == 1) {
                ans--;ans--;
            }
        }
        for(int i = 0; i < grid.size() - 1; i++) {
            if(grid[i][grid[0].size() - 1] == 1 && grid[i+1][grid[0].size() - 1] == 1) {
                ans--;ans--;
            }
        }
        return ans;
    }
};