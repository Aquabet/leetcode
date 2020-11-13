#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void find(int i, int j, vector<vector<char>>& grid) {
        if(i+1 < grid.size()) {
            if(grid[i+1][j] == '1') {
                grid[i+1][j] = '9';
                find(i+1,j,grid);
            }
        }
        if(j+1 < grid[0].size()) {
            if(grid[i][j+1] == '1') {
                grid[i][j+1] = '9';
                find(i,j+1 ,grid);
            }
        }
        if(i > 0) {
        	if(grid[i-1][j] == '1') {
                grid[i-1][j] = '9';
                find(i-1,j,grid);
		    }
        }
		if(j > 0) {
			if(grid[i][j-1] == '1') {
                grid[i][j-1] = '9';
			    find(i,j-1,grid);
		    }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        if(grid[0].size() == 0) return 0;
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    grid[i][j] = '9';
                    find(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};