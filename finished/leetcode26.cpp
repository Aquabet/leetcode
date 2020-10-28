#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) {
            return nums.size();
        }
        int prenum = nums[0];
        int next = 0;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == prenum) {
                next++;
            }
            else {
                prenum = nums[i];
                nums[i - next] = nums[i];
            }
        }
        return nums.size() - next;
    }
};