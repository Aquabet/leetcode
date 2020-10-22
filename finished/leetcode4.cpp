#include<vector>
#include<queue>
using namespace std;
//O(nlogn慢出天际 有空重构一下)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int >q;
        double ans;
        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();
        for(;it1 != nums1.end();it1++){
            q.push(*it1);
        }
        for(;it2 != nums2.end();it2++){
            q.push(*it2);
        }
        int keynum = q.size()/2;
        if(q.size()%2 == 0){
            for(int i = 0;i < keynum -1;i++){
                q.pop();
            }
            ans = q.top();
            q.pop();
            ans += q.top();
            ans /= 2;
        }
        else if(q.size()%2 == 1){
            for(int i =0 ;i < keynum;i++){
                q.pop();
            }
            ans = q.top();
        }
        return ans;
    }
};