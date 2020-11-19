#include<bits/stdc++.h>
using namespace std;
/*
建立无向图并BFS
*/
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        set<string> wordList;
        int num = friends.size();
        vector<vector<bool>> connect(num, vector<bool>(num));
        for(int i = 0; i < num; i++) {
            for(int j = 0; j < friends[i].size(); j++) {
                connect[i][j] = connect[j][i] = true;
            }
        }
        for(int i = 0; i < num; i++) {
            if(i != id && connect[i][j] == true) {
                
            }
        }
    }
};