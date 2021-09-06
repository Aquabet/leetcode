#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int size = chars.size();
        int fast = 0;
        int slow = 0;
        int writep = 0;
        char nowch = chars[0];
        do {
            while(chars[fast] == nowch) {
                fast++;
                if(fast == size) break;
            }
            chars[writep++] = nowch;
            if(fast - slow > 1) {
                string num = to_string(fast - slow);
                int sizen = num.size();
                int rbq = sizen;
                while(rbq) {
                    chars[writep++] = num[sizen - rbq];
                    rbq--;
                }
            }
            slow = fast;
            if(slow < size){
                nowch = chars[slow];
            }
        } while(fast < size);
        if(size > writep)
        chars.resize(writep);
        return chars.size();
    }
};