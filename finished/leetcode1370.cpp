#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string sortString(string s) {
        int length = s.length();
        if(length == 0) return s;
        set<char > s;
        map<char, int > compar;
        map<char, int >::iterator it;
        string ans;
        for(int i = 0; i < 26; i++) {
            compar.insert(pair<char, int >('a'+i,0));
        }
        for(int i = 0; i < length; i++) {
            compar[s[i]]++;
        }
        while(ans.length() != length) {
            for(int i = 0; i < 26; i++) {
                if(compar['a'+i] != 0) {
                    compar['a'+i]--;
                    ans.push_back('a'+i);
                }
            }
            for(int i = 25; i >= 0; i--) {
                if(compar['a'+i] != 0) {
                    compar['a'+i]--;
                    ans.push_back('a'+i);
                }
            }
        }
    return ans;
    }
};