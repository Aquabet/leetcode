#include<bits/stdc++.h>
using namespace std;
/*
  声明：本代码来源：我读错题了！
  原题中只要level级朋友看过的视频都视为level级视频
  本代码适用于视频i的等级 level[i] 为最近朋友的等级
  即每个视频仅有1个level 为"我"与该视频最近的主人的层数
*/


    static bool cmp(const pair<string, pair<int, int > > &a, const pair<string, pair<int, int > > &b) {
        if(a.second.second != b.second.second) return a.second.second < b.second.second;
        return a.first < b.first;
    }

    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int num = friends.size();
        vector<vector<int>> connect(num, vector<int>(num));
        vector<bool > read(num);
        map<string, pair<int ,int> > times;//pair.first = level, second = times
        map<string, pair<int ,int>>::iterator it;
        for(int i = 0; i < num; i++) {
            for(int j = 0; j < friends[i].size(); j++) {
                connect[i][friends[i][j]] = connect[friends[i][j]][i] = 1;
            }
        }//建图

        stack<int > find1;
        find1.push(id);
        read[id] = true;
        for(int i = 0; i < watchedVideos[id].size(); i++) {
            it = times.find(watchedVideos[id][i]);
            if(it == times.end()) times.insert(pair<string, pair<int, int > >(watchedVideos[id][i], pair<int, int >(0, 1)));
            else times[watchedVideos[id][i]].second++;
        }//处理level0

        for(int i = 0; i < level; i++) {
            stack<int > find2;
            while(find1.empty() == false) {
                int top = find1.top();
                for(int i = 0; i < num; i++) {
                    if(connect[i][top] == 1 && i != top && read[i] == false) {
                        find2.push(i);
                        read[i] = true;
                        for(int j = 0; j < watchedVideos[i].size(); j++) {
                            it = times.find(watchedVideos[i][j]);
                            if(it == times.end()) times.insert(pair<string, pair<int, int > >(watchedVideos[i][j], pair<int, int >(i, 1)));
                            else times[watchedVideos[i][j]].second++;
                        }
                    }
                }
                find1.pop();
            }
            find1 = find2;
        }//迭代level次
        
        vector<pair<string, pair<int, int > > > fakeans;
        vector<string> ans;
        for(auto x: times) {
            fakeans.push_back(x);
        }
        sort(fakeans.begin(), fakeans.end(),cmp);
        for(int i = 0; i < fakeans.size(); i++) {
            if(fakeans[i].second.first == level) ans.push_back(fakeans[i].first);
        }
        return ans;
    }

int main() {
    vector<vector<string>> watchedVideos = {{"A","B"},{"C"},{"B","C"},{"D"}};
    vector<vector<int>> friends = {{1,2},{0,3},{0,3},{1,2}};
    int id = 0;
    int level = 1;
    watchedVideosByFriends(watchedVideos, friends, id, level);
    cout<<"MISSION ACCOMPLISHED"<<endl;
}
