#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void find1(int& m, int& n, int p, int q, vector<vector<int>>& matrix, vector<vector<bool>>& read1) {
        if(read1[p][q] == true) return;
        read1[p][q] = true;
        if(p + 1 < m) {
            if(matrix[p + 1][q] >= matrix[p][q] && read1[p + 1][q] == false) {
                find1(m, n, p+1, q, matrix, read1);
            }
        }
        if(q + 1 < n) {
            if(matrix[p][q + 1] >= matrix[p][q] && read1[p][q + 1] == false) {
                find1(m, n, p, q+1, matrix, read1);
            }
        }
        if(p - 1 > -1) {
            if(matrix[p - 1][q] >= matrix[p][q] && read1[p - 1][q] == false) {
                find1(m, n, p-1, q, matrix, read1);
            }
        }
        if(q - 1 > -1) {
            if(matrix[p][q - 1] >= matrix[p][q] && read1[p][q - 1] == false) {
                find1(m, n, p, q-1, matrix, read1);
            }
        }
    }

    void find2(int& m, int& n, int p, int q, vector<vector<int>>& matrix, vector<vector<bool>>& read2) {
        if(read2[p][q] == true) return;
        read2[p][q] = true;
        if(p + 1 < m) {
            if(matrix[p + 1][q] >= matrix[p][q] && read2[p + 1][q] == false) {
                find2(m, n, p+1, q, matrix, read2);
            }
        }
        if(q + 1 < n) {
            if(matrix[p][q + 1] >= matrix[p][q] && read2[p][q + 1] == false) {
                find2(m, n, p, q+1, matrix, read2);
            }
        }
        if(p - 1 > -1) {
            if(matrix[p - 1][q] >= matrix[p][q] && read2[p - 1][q] == false) {
                find2(m, n, p-1, q, matrix, read2);
            }
        }
        if(q - 1 > -1) {
            if(matrix[p][q - 1] >= matrix[p][q] && read2[p][q - 1] == false) {
                find2(m, n, p, q-1, matrix, read2);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int m = matrix.size();
        if(m == 0) return ans;
        int n = matrix[0].size();
        if(n == 0) return ans;
        vector<vector<bool>> read1(m, vector<bool>(n));
        vector<vector<bool>> read2(m, vector<bool>(n));
        for(int i = 0; i < n; i++) {
            find1(m, n, 0, i, matrix, read1);
        }
        for(int i = 0; i < m; i++) {
            find1(m, n, i, 0, matrix, read1);
        }
        for(int i = 0; i < n; i++) {
            find2(m, n, m-1, i, matrix, read2);
        }
        for(int i = 0; i < m; i++) {
            find2(m, n, i, n-1, matrix, read2);
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(read1[i][j] == true && read2[i][j] == true) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};