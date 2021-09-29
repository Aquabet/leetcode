#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinMoves(vector<int> &machines) {
        int size = machines.size();
        int sum = 0;
        int fMac[size];
        int ans = 0;
        for(int i = 0; i < size; i++) {
            sum += machines[i];
        }
        if(sum % size != 0) {
            return -1;
        }
        int average = sum / size;
        for(int i = 0; i < size; i++) {
            machines[i] -= average;
            fMac[i] = machines[i];
        }
        for(int i = 1; i < size; i++) {
            machines[i] += machines[i-1];
        }
        for(int i = 0; i < size; i++) {
            ans = max(max(ans, abs(machines[i])), fMac[i]);
        }
        return ans;
    }
};