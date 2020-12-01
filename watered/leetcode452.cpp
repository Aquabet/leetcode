#include<bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator ()(pair<int ,int > &a,pair<int ,int > &b){
        return a.first < b.first;
    }
};
    priority_queue <int, vector<pair<int, int > >, cmp > que;