#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> volunteerDeployment(vector<int>& finalCnt, long long totalNum, vector<vector<int>>& edges, vector<vector<int>>& plans) {
        int n = finalCnt.size() + 1;
        int xNum[n];
        memset(xNum, 0, sizeof(xNum));
        vector<long long > ans(n);
        for(int i = 1; i < n; i++) ans[i] = finalCnt[i - 1];
        xNum[0] = 1;
        vector<vector <int> >mappa(n);
        int edgesize = edges.size();
        for(int i = 0; i < edgesize; i++) {
            mappa[edges[i][0]].push_back(edges[i][1]);
            mappa[edges[i][1]].push_back(edges[i][0]);
        }
        int plansize = plans.size() - 1;
        for(int i = plansize; i >= 0; i--) {
            int planNum = plans[i][0];
            if(planNum == 1) {
                ans[plans[i][1]] *= 2;
                xNum[plans[i][1]] *= 2;
            }
            else if(planNum == 2) {
                int mappasize = mappa[plans[i][1]].size();
                for(int j = 0; j < mappasize; j++) {
                    ans[mappa[plans[i][1]][j]] -= ans[plans[i][1]];
                    xNum[mappa[plans[i][1]][j]] -= xNum[plans[i][1]];
                }
            }
            else {
                int mappasize = mappa[plans[i][1]].size();
                for(int j = 0; j < mappasize; j++) {
                    ans[mappa[plans[i][1]][j]] += ans[plans[i][1]];
                    xNum[mappa[plans[i][1]][j]] += xNum[plans[i][1]];
                }
            }
        }
        long long sum = 0;
        long long xSum = 0;
        for(int i = 0; i < n; i++) {
            sum += ans[i];
            xSum += xNum[i];
        }
        long long x = (totalNum - sum) / xSum;
        for(int i = 0; i < n; i++) {
            ans[i] = ans[i] + x*xNum[i];
        }
        vector<int > tAns(n);
        for(int i = 0; i < n; i++) {
            tAns[i] = ans[i];
        }
        return tAns;
    }
};