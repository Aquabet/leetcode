#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int moveway = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) moveway++;
            else nums[i - moveway] = nums[i];
        }
        int k = nums.size() - moveway;
        while(k != nums.size()) {
            nums[k] = 0;
            k++;
        }
    }
};