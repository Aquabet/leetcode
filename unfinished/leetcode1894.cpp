#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int size = chalk.size();
        int sumC[size];
        if(chalk[0] > k) return 0;
        sumC[0] = chalk[0];
        for(int i = 1; i < size; i++) {
            sumC[i] = chalk[i] + sumC[i-1];
            if(sumC[i] > k) return i;
        }
        int res = k % sumC[size - 1];
        return upper_bound(sumC, sumC+size, res) - sumC;

    }
};