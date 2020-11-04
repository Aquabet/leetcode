#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if(A.size() < 3) {
            return false;
        }
        vector<int> left(n);
        for (int i = 1; i < n; ++i) {
            left[i] = (A[i - 1] < A[i] ? left[i - 1] + 1 : 0);
        }
        vector<int> right(n);
        for (int i = n - 2; i >= 0; --i) {
            right[i] = (A[i + 1] < A[i] ? right[i + 1] + 1 : 0);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (left[i] > 0 && right[i] > 0) {
                ans = max(ans, left[i] + right[i] + 1);
            }
        }//改编自leetcode845
        if(ans == A.size()) return true;
        return false;
    }
};