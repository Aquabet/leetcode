#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size = nums.size();
        int a[size];
        int pos1;
        int pos2;
        for(int i = 0; i < size; i++) {
            a[i] = nums[i];
        }
        sort(a, a + size);
        for(int i = 0; i < size; i++) {
            if(a[i] != nums[i]) {
                pos1 = i;
                break;
            }
        }
        for(int i = size - 1; i >= 0; i--) {
            if(a[i] != nums[i]) {
                pos2 = i;
                break;
            }
        }
        return pos2 <= pos1 ? 0 : pos2-pos1+1;
    }
};