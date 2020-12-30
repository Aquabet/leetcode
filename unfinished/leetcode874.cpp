#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int > > aSet;
        int osize = obstacles.size();
        int size = commands.size();
        int nowx = 0;
        int nowy = 0;
        for(int i = 0; i < osize; i++) {
            aSet.insert(pair<int, int > (obstacles[i][0],obstacles[i][1]));
        }
        int flag = 0;
        for(int i = 0; i < size; i++) {
            if(commands[i] == -2) {
                flag = (flag + 3) % 4;
                continue;
            }
            if(commands[i] == -1) {
                flag = (flag + 1) % 4;
                continue;
            }
            if(flag == 0) {
                nowy -= commands[i];
            }
            if(flag == 1) {
                nowx += commands[i];
            }
            if(flag == 2) {
                nowy += commands[i];
            }
            if(flag == 3) {
                nowx -= commands[i];
            }
            
        }
    }
};