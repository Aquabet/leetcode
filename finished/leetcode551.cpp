#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkRecord(string s) {
        int len = s.length();
        int aNow = 0;
        int lNow = 0;
        for(int i = 0; i < len; i++) {
            if(s[i] == 'P') {
                lNow = 0;
            }   else if(s[i] == 'L') {
                lNow++;
            }   else {
                lNow = 0;
                aNow++;
            }
            if(lNow == 3 || aNow == 2) {
                return false;
            }
        }
        return true;
    }
};