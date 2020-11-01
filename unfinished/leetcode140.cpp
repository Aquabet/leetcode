#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector <vector <int > > v;
        vector<string> ans;
        string nowans;
        for(int i = 0; i < wordDict.size(); i++) {
            string rbq;
            int p = 0;
            while(p < wordDict.size()) {
                rbq = wordDict[i].substr(p);
                int pisition = rbq.find(wordDict[i]);
                if(pisition == rbq.npos) {
                    break;
                }
                v[i].push_back(pisition);
                p += wordDict.size();
                p++;
            }
        }


    }
};

/*
//查找s 中flag 出现的所有位置。
    flag="a";
    position=0;
    int i=1;
    while((position=s.find(flag,position))!=string::npos)
    {
        cout<<"position  "<<i<<" : "<<position<<endl;
        position++;
        i++;
    }
    */