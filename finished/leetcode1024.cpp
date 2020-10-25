#include<iostream>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#define INT_MAX 2147483647

class Solution {
public:

    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= T; i++) {
            for (vector<vector<int>>::iterator it = clips.begin();it != clips.end();it++) {
                if ((*it)[0] < i && i <= (*it)[1]) {
                    dp[i] = min(dp[i], dp[(*it)[0]] + 1);
                }
            }
        }
        return dp[T] == INT_MAX - 1 ? -1 : dp[T];
    }
};
