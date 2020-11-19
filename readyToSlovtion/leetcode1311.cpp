#include<bits/stdc++.h>
using namespace std;
/*
建立无向图并BFS
*/
class Solution {
public:
    static bool cmp(const pair<string, int > &a, const pair<string, int > &b) {
        if(a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    }

    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        set<string> wordList;
        int num = friends.size();
        vector<vector<int>> connect(num, vector<int>(num));
        for(int i = 0; i < num; i++) {
            for(int j = 0; j < friends[i].size(); j++) {
                connect[i][friends[i][j]] = connect[friends[i][j]][i] = 1;
            }
        }
        vector<bool > read(num);
        read[id] = true;
        stack<int > find1;
        for(int i = 0; i < num; i++) {
            if(i != id && connect[i][id] == 1 && read[i] == false) {
                find1.push(i);
                read[i] = true;
            }
        }
        for(int i = 1; i < level; i++) {
            stack<int > find2;
            while(find1.empty() == false) {
                int top = find1.top();
                for(int i = 0; i < num; i++) {
                    if(connect[i][top] == 1 && i != top && read[i] == false) {
                        find2.push(i);
                        read[i] = true;
                    }
                }
                find1.pop();
            }
            find1 = find2;
        }
        map<string, int > times;
        map<string, int>::iterator it;
        while(find1.empty() == false) {
            int top = find1.top();
            for(int i = 0; i < watchedVideos[top].size(); i++) {
                it = times.find(watchedVideos[top][i]);
                if(it == times.end()) times.insert(pair<string, int>(watchedVideos[top][i], 1));
                else times[watchedVideos[top][i]]++;
            }
            find1.pop();
        }
        vector<pair<string, int > > fakeans;
        vector<string> ans;
        for(auto x: times) {
            fakeans.push_back(x);
        }
        sort(fakeans.begin(), fakeans.end(),cmp);
        for(int i = 0; i < fakeans.size(); i++) {
            ans.push_back(fakeans[i].first);
        }
        return ans;
    }
};