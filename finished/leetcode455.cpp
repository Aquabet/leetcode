#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int slength = s.size();
        if(!slength) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j = 0;
        int ans = 0;
        int flag = 0;
        for(int i = 0; i < g.size(); i++) {
            if(j == slength) break;
	        while(g[i] > s[j]) {
	            j++;
	            if(j == slength) {
	            	flag = 1;
	            	break;
				}
	        }
	        if(flag) break;
	        if(g[i] <= s[j]) {
		        j++;
	            ans++;
		    }
		}
	    return ans;
	}
};