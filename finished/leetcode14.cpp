#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int lenth = strs.size();
        int shortest = 0;
        for(int i = 0;i < lenth;i++) {
            int length = strs[i].length();
            if(length >= shortest) {
                shortest = length;
            }
        }
        for(int i = 0;i < shortest;i++) {
            char c = strs[0][i];
            for(int j= 1;j < lenth;j++) {
                if(strs[j][i] != c) {
                    return ans;
                }
            }
            ans.push_back(c);
        }
        return ans;
    }
};