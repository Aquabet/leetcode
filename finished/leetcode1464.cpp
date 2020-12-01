#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = -1;
        int size = nums.size();
        for(int i = 0; i <size; i++) {
            for(int j = 0; j < i; j++) {
                ans = max(ans, (nums[i]-1)*(nums[j]-1));
            }
        }
        return ans;
    }
};