#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.length() == 0) return s;
        string ans;
        for(int nowrow = 1;nowrow <= numRows;nowrow++){
            int p = nowrow -1;
            int dir = 1;
            while(p < s.length()){
                if(nowrow == 1 || nowrow == numRows){
                    ans.push_back(s[p]);
                    p += 2 * (numRows - 1);
                }
                else{
                    ans.push_back(s[p]);
                    if(dir == 1){
                        p += 2 * (numRows - nowrow);
                    }
                    else{
                        p += 2 * (nowrow - 1);
                    }
                }
                dir *= -1;
            }
        }
        return ans;
    }
};