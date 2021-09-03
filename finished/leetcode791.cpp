#include<bits/stdc++.h>
using namespace std;

map<char, int > mapp;

bool cmp(char a, char b) {
    return mapp[a] < mapp[b];
}

class Solution {
public:
    string customSortString(string order, string s) {
        const int INF = 1000;
        mapp.clear();
        int slen = s.size();
        int olen = order.length();
        for(char i = 'a'; i <= 'z'; i++) {
            int plac = find(order.begin(), order.end(), i) - order.begin();
            if(plac == olen) {
                mapp.insert(pair<char, int > (i, INF));
            } else {
                mapp.insert(pair<char, int > (i, plac));
            }
        }
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};