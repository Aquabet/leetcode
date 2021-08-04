#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0 ;i < size - 2; i++) {
            if(nums[i] == 0) continue;
            for(int j = i + 1; j < size - 1; j++) {
                ans += lower_bound(nums.begin() + j + 1, nums.end(), 
                    nums[i] + nums[j]) - nums.begin() - j - 1;
            }
        }
        return ans;
    }
};