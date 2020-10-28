#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int small = 0;
        int mid = 0;
        int big = 0;
        stack<int>nowleft;
        int p = 0;
        while(p != s.length()) {
            if(s[p] == '[') {
                mid++;
                nowleft.push(1);
                goto heiheihei;
            }
            if(s[p] == '(') {
                small++;
                nowleft.push(0);
                goto heiheihei;
            }
            if(s[p] == '{') {
                big++;
                nowleft.push(2);
                goto heiheihei;
            }
            if(nowleft.empty() == true) return false;
            if(s[p] == ')') {
                if(nowleft.top() != 0 || small <= 0) return false;
                small--;
                nowleft.pop();
                goto heiheihei;
            }
            if(s[p] == ']') {
                if(nowleft.top() != 1 || mid <= 0) return false;
                mid--;
                nowleft.pop();
                goto heiheihei;
            }
            if(s[p] == '}') {
                if(nowleft.top() != 2 || big <= 0) return false;
                big--;
                nowleft.pop();
                goto heiheihei;
            }
            heiheihei :
            p++;
        }
        if(small != 0 || mid != 0 || big != 0 || nowleft.empty() == false) {
            return false;
        }
        return true;
    }
};