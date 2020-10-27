#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int times[2005] = {0};
        int ans[2005] = {0};
        for(int i = 0;i < arr.size();i++){
            times[arr[i]+1001]++;
        }

        for(int i = 0;i < 2005;i++){
            if(times[i] != 0){
                ans[times[i]]++;
            }
        }
        for(int i = 0;i < 2005;i++){
            if(ans[i] > 1){
                return false;
            }
        }
        return true;
    }
};