#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(int a, int b) {
        return a > b;
    }
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end(), cmp);
        nums.resize(2 * size);
        for(int i = size - 1; i >= 0; i--) {
            nums[2 * i] = nums[i];
        }
        int j = 1;
        for(int i = 2 * (size -1); i >= size; i -= 2) {
            nums[j] = nums[i];
            j += 2;
        }
        nums.resize(size);
    }
};