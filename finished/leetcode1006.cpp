#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int clumsy(int N) {
        bool opa = 0;
        long long ans1, finalans = 0;
        int nown = N;
        int flag = 1;
        if(nown > 3) {
            flag = 0;
            finalans = nown*(nown - 1)/(nown - 2)+nown - 3;
            nown -= 4;
            while(nown >= 4) {
                finalans -=  nown*(nown - 1)/(nown - 2) - nown + 3;
                nown -= 4;
            }
        }
        if(flag == 0) {
            if(nown == 0) return finalans;
            else if(nown == 1) return finalans - 1;
            else if(nown == 2) return finalans - 2;
            else if(nown == 3) return finalans - 6;
        }
        else {
            if(nown == 0) return 0;
            else if(nown == 1) return 1;
            else if(nown == 2) return 2;
            else if(nown == 3) return 6;
        }
    }
};