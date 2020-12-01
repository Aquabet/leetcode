#include<bits/stdc++.h>
using namespace std;
/*
复杂度可降低
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if(size < 1) return 0;
        int ans = -1;
        sort(nums.begin(),nums.end());
        for(int i = 1; i < size; i++) {
            ans = max(nums[i] - nums[i-1], ans);
        }
        return ans;
    }
};