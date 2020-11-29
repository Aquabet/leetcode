#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reorganizeString(string S) {
        int length = S.length();
        char last = '1';
        for(int i = 0; i < length; i++) {
            if(S[i] != last) {
                last = S[i];
                continue;
            }
            int j = i + 1;
            bool flag = false;
            while(j < length) {
                if(S[j] != last) {
                    last = S[j];
                    swap(S[i], S[j]);
                    flag = true;
                    break;
                }
                j++;
            }
            if(flag == false)  return "";
        }
        return S;
    }
};