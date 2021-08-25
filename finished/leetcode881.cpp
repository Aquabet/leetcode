#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int size = people.size();
        bool used[size];
        memset(used, false, sizeof(used));
        sort(people.begin(), people.end());
        int ans = 0;
        for(int i = 0; i < size; i++) {
            if(!used[i]) {
                used[i] = true;
                int goalWeight = limit - people[i];
                int p = upper_bound(people.begin()+i, people.end(), goalWeight) - people.begin() - i - 1;
                if(p == size - i + 1 || p <= 0) {
                    ans += 1;
                    continue;
                }
                while(p > 0 && used[i+p] == true) {
                    p--;
                }
                if(p == 0) {
                    ans += 1;
                    continue;
                };
                used[i+p] = true;
                ans += 1;
            }
        }
        return ans;
    }
};