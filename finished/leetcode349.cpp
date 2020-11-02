#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int > ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int p1 = 0, p2 = 0;
        if(nums1.size() == 0 || nums2.size() == 0) {
            return ans;
        }
        int last1 = nums1[0] - 1, last2 = nums2[0] - 1;
        while(p1 != nums1.size() && p2 != nums2.size()) {
            if(nums1[p1] == last1 || nums1[p1] < nums2[p2]) {
                p1++;
                continue;
            }
            if(nums2[p2] == last2 || nums1[p1] > nums2[p2]) {
                p2++;
                continue;
            }
            if(nums1[p1] == nums2[p2]) {
                ans.push_back(nums2[p2]);
            }
            last1 = nums1[p1];
            last2 = nums2[p2];
            p1++;p2++;

        }
        return ans;
    }
};