#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size = arr.size();
        for(int i = 1; i < size; i++) {
            if(arr[i] < arr[i - 1]) return i-1;
        }
        return size;
    }
};