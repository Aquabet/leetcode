#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string toHex(int num) {
        if(num == -2147483648) return "80000000";
        string ans;
        vector<bool > v(32);
        int ptr = 31;
        v[0] = num <= 0;
        num = abs(num);
        bool zero = true;
        while(num != 0) {
            v[ptr] = num % 2;
            num /= 2;
            ptr--;
        }
        if(v[0]) {
            ptr = 31;
            v[0] = 1;
            for(int i = 1; i < 32; i++) {
                v[i] = !v[i];
            }
            bool buffer = v[31] == true;
            if(!buffer) v[31] = true;
            while(buffer == true && ptr >= 0) {
                if(v[ptr] == true) {
                    v[ptr] = false;
                    ptr--;
                } else {
                    v[ptr] = true;
                    buffer = false;
                }
            }
        }
        for(int i = 0; i < 8; i++) {
            int sum = 0;
            for(int j = 0; j < 4; j++) {
                sum <<= 1;
                sum += v[i*4 + j];
            }
            if(zero && sum == 0) continue;
            zero = false;
            ans.push_back(sum>=10?'a'+sum-10:sum+'0');
        }
        if(ans.empty()) ans.push_back('0');
        return ans;
    }
};