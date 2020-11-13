#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int front = 0;
        for(int i = 0;i < s.length(); i++) {
            front = t.find(s[i],front);
            if(front == s.npos) return false;
        }
        return true;
    }
};