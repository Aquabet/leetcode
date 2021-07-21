#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int numnow = 0;
        int size = nums.size();
        int size2 = size / 2;
        for(int i = 0; i < size2; i++) {
            numnow = max(numnow, nums[i] + nums[size-i]);
        }
        return numnow;
    }
};