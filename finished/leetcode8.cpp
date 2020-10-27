#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int p = 0;
        int flag = 1;
        int boomflag = 0;
        long long ans = 0;
        while(s[p] == ' '){
            p++;
        }
        if(s[p] == '-'){
            flag = -1;
            p++;
        }
        else if(s[p] == '+'){
            p++;
        }
        while(s[p]>='0' && s[p]<='9'){
            ans *= 10;
            ans += (s[p] - '0');
            p++;
            if(ans > (long long)INT_MAX && flag == 1) {
                return INT_MAX;
            }
            else if(ans > (long long)INT_MAX+1 &&flag == -1){
                return INT_MIN;
            }
        }
        if(boomflag == 1){
            return (flag == 1 ? INT_MAX :INT_MIN);
        }
        return ans*flag;
    }
};