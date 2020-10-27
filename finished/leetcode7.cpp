#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        int flag = 1;

        while(x != 0){
            ans *= 10;
            ans += x%10;
            x /= 10;
        }

        if(abs(ans) > INT_MAX) return 0;
        return (int)ans;
    }
};