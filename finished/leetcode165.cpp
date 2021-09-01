#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length();
        int len2 = version2.length();
        queue<int > que[2];
        int nowhead1 = 0;
        int nowhead2 = 0;
        for(int i = 0; i < len1; i++) {
            if(version1[i] == '.') {
                que[0].push(i);
            }
        }
        for(int i = 0; i < len2; i++) {
            if(version2[i] == '.') {
                que[1].push(i);
            }
        }
        que[0].push(len1);
        que[1].push(len2);
        int tail1, tail2;
        int num1, num2;
        while(!que[0].empty()||!que[1].empty() ) {
            if(!que[0].empty() ) {
                tail1 = que[0].front();
                // cout<<"tail1"<<tail1<<endl;
                num1 = atoi(version1.substr(nowhead1, tail1).c_str() );
                // cout<<"num1"<<num1<<endl;
                nowhead1 = tail1 + 1;
                que[0].pop();
            }
            else {
                num1 = 0;
            }
            if(!que[1].empty() ) {
                tail2 = que[1].front();
                // cout<<"tail2"<<tail2<<endl;
                num2 = atoi(version2.substr(nowhead2, tail2).c_str() );
                // cout<<"num2"<<num2<<endl;
                nowhead2 = tail2 + 1;
                que[1].pop();
            }
            else {
                num2 = 0;
            }

            if(num1 > num2) {
                return 1;
            }
            else if (num1 < num2) {
                return -1;
            }
        }
        return 0;
    }
};