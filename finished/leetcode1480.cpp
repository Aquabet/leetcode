#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans;
        int now = 0;
        for(int i = 0; i < len; i++) {
            now += nums[i];
            ans.push_back(now);
        }
        return ans;
    }
};