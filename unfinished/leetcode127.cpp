#include<bits/stdc++.h>
using namespace  std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size() == 0) {
            return 0;
        }
        int length = wordList.size();
        bool mapp[length][length];
        int beginplace;
        int endplace;
        int last[length] = {-1};
        bool read[length] = {false};
        memset(mapp,false,sizeof(mapp));
        for(int i = 0; i < length; i++) {
            if(beginWord == wordList[i]) {
                beginplace = i;
            }
            if(endWord == wordList[i]) {
                endplace = i;
            }
            for(int j = 0; j < length; j++) {
                int flag = 0;
                for(int k = 0; k < wordList[0].length(); k++) {
                    if(wordList[i][k] != wordList[j][k]) {
                        if(flag == 1) {
                            mapp[i][j] = false;
                            mapp[j][i] = false;
                            goto break1;
                        }
                        else {
                            flag = 1;
                        }
                    }
                }
                break1 :
            }
        }

        queue<int> find;
        find.push(beginplace);
        read[beginplace] = true;
        while(find.empty() == false || read[endplace] == false) {
            for(int i = 0; i < length; i++) {
                int head = find.front();
                if(mapp[head][i] == true && read[i] == false) {
                    find.push(i);
                    last[i] = head;
                    read[i] = true;
                }
                find.pop();
            }
        }
        if(last[endplace] == -1) return 0;
        else {
            int ans = 0;
            int p = endplace;
            while(p != beginplace) {
                p = last[p];
                ans++;
            }
            return ans;
        }
    }
};