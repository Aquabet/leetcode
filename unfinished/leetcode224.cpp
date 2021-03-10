#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int func(string s, int p) {

    }

    pair<int, int> Strtoint(string s, int p) {
        int ans = 0;
        int mov = 0;
        while(s[p] >= '0' && s[p] <= '9') {
            ans *= 10;
            ans += s[p]-'0';
            mov++;
        }
        return {ans,mov};
    }

    int calculate(string s) {
        int length = s.length();
        int ans = 0;
        int p = 0;
        while(p < length) {
            if(s[p] == ' ') {
                p++;
            }
            else if(s[p] >= '0' && s[p] <= '9'){
                pair<int, int> pai = Strtoint(s, p);
                ans += pai.first;
            }
        }
    }
};