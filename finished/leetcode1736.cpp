#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string maximumTime(string time) {

        string ans;

        if(time[0] == '?' && time[1] == '?') {
            ans += "23";
        } else if(time[1] == '?') {
            if(time[0] == '2') {
                ans += "23";
            } else {
                ans += time[0];
                ans += "9";
            }
        } else if(time[0] == '?') {
            if(time[1] <= '3') {
                ans += "2";
                ans += time[1];
            } else {
                ans += "1";
                ans += time[1];
            }
        } else {
            ans += time[0];
            ans += time[1];
        }

        ans += ":";

        if(time[3] == '?' && time[4] == '?') {
            ans += "59";
        } else if(time[3] == '?') {
            ans += "5";
            ans += time[4];
        } else if(time[4] == '?') {
            ans += time[3];
            ans += "9";
        } else {
            ans += time[3];
            ans += time[4];
        }
        return ans;
    }
};