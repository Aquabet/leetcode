#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        if(n < 2) return 0;
        vector<bool > isPrime(n, true);
        for(int i = 2; i < n; i++) {
            if(isPrime[i] == true) {
                for(int j = 2; i * j < n; j++) {
                    isPrime[i*j] = false;
                }
            }
        }

        for(int i = 2; i < n; i++) {
            if(isPrime[i] == true) {
                ans++;
            }
        }
        return ans;
    }
};