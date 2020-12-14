#include<bits/stdc++.h>
using namespace std;

//2,3,4,5,6,7,8,9
//0,1,2,3,4,5,6,7
//find 2
//1->5
//2->1
//3->0
//find 8
//1->5
//2->7
//3->6
// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         if(nums.size() == 0) {
//             return 0;
//         }
//         if(nums[0] >= target) {
//             return 0;
//         }
//         if(nums[nums.size() - 1] <= target) {
//         	return nums.size();
// 		}

//         int head = 0;
//         int tail = nums.size()-1;
//         int p = (head+tail)/2;
//         while(head != tail && !(nums[p-1] < target && nums[p] >= target)) {
//             p = (head+tail)/2;
//             if(nums[p] > target) {
//                 tail = p;
//             }
//             if(nums[p] < target) {
//             	head = p;
// 			}
//             if(head + 1 == tail) {
//                 p = tail;
//                 break;
//             }
//         }
//         return p;
//     }
// };
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(),nums.end(),target) - nums.begin();
    }
};