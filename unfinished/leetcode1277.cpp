#include<bits/stdc++.h>>
using namespace std;

class Solution {
public:

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int square = min(m, n) + 1;
        int ans = 0;

        int squ[square];
        squ[0] = 0;
        for(int i = 1; i <= square; i++) {
            squ[i] = squ[i-1] + i*i;
        }
        while(--square) {
            for(int i = 0; i + square < m; i++) {
                for(int j = 0; j + square < n; j++) {

                }
            }
        }


    }
};