#include<vector>
#include<iostream>
using namespace std;
static const auto _ = []() { ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        for(int i = 0;i < nums.size();i++){
            for(int j = 0;j < nums.size();j++){
                if(nums[i] > nums[j]){
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};