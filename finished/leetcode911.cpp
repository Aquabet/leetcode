#include<bits/stdc++.h>
using namespace std;

class TopVotedCandidate {
public:
    vector<int > timetic;
    vector<int > nowvictors;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        timetic.clear();
        nowvictors.clear();
        int size = persons.size();
        int score[size];
        memset(score, 0, sizeof(score));
        int nowvictor = 0;
        for(int i = 0; i < size; i++) {
            score[persons[i]]++;
            if(score[persons[i]] >= score[nowvictor]) {
                nowvictor = persons[i];
                timetic.push_back(times[i]);
                nowvictors.push_back(persons[i]);
            }
        }
    }
    
    int q(int t) {
        int timet = upper_bound(timetic.begin(), timetic.end(), t) - timetic.begin();
        if(timet == 0 && timetic[timet] > t) {
            return NULL;
        }
        return nowvictors[timet-1];
    }
};


// ["TopVotedCandidate","q","q","q","q","q","q","q","q","q","q"]
// [[[0,0,0,0,1],[0,6,39,52,75]],[45],[49],[59],[68],[42],[37],[99],[26],[78],[43]]

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */