#include<string>
#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        vector<int> a[26];
        bool inqueue = false;
        int queue_head_point = -1;
        int queue_last_point = -1;
        for (int i = 0 ; i < S.length() ; i++){
            if(S[i] >= 'a' && S[i] <= 'z'){
                a[S[i]-'a'].push_back(i);
            }
        }//ababcbacadefegdehijhklij 
        for(int i = 0 ; i < S.length() ; i++){
            if(i == queue_last_point && inqueue == true) {
                inqueue = false;
                ans.push_back(i-queue_head_point+1);
                continue;
            }//queue尾
            if(inqueue == false){
                queue_head_point = i;
                queue_last_point = a[S[i] - 'a'].back();
                if(queue_head_point != queue_last_point){
                    inqueue = true;
                }
                else {
                    ans.push_back(1);
                }
                continue;
            }
            if(inqueue == true && i != queue_last_point){
                if(a[S[i] - 'a'].back() > queue_last_point){
                    queue_last_point = a[S[i] - 'a'].back();
                }
                continue;
            }
        }
        return ans;
    }
};