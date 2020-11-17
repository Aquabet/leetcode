#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int nowgas;
        int size  = gas.size();
        for(int i = 0; i < size; i++) {
            nowgas = gas[i];
            int j ;
            for(j = 0; j < size; j++) {
                nowgas -= cost[(i + j) % size];
                if(nowgas < 0) break;
                nowgas += gas[(i + j + 1) % size];
            }
            if(j == size - 1) return i;
        }
        return -1;
    }
};