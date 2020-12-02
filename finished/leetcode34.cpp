#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int pos2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(pos1 == nums.size() || pos1 > pos2) return{-1,-1};
        return {pos1, pos2-1};
    }
};