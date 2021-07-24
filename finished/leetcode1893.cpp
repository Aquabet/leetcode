#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool covered[55];
        memset(covered, false, sizeof(covered));
        int size = ranges.size();
        for(int i = 0; i < size; i++) {
            for(int j = ranges[i][0]; j <= ranges[i][1]; j++) {
                covered[j] = true;
            }
        }
        for(int i = left; i <= right; i++) {
            if(covered[i] == false) {
                return false;
            }
        }
        return true;
    }
};