#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int p1 = 0, p2 = 1;
        vector<int >ans(A.size());
        for(int i = 0; i < A.size(); i++) {
            if(i % 2 == 0) {
                ans[p1] = A[i];
                p1 += 2;
            }
            else{
                ans[p2] = A[i];
                p2 += 2;
            }
        }
        return ans;
    }
};