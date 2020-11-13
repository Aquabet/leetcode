#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) {
                five++;
            }
            if(bills[i] == 10) {
                ten++;
                if(five ==0) return false;
                else five--;
            }
            if(bills[i] == 20) {
                if((ten > 0 && five > 0 ) || five > 2) {
                    if(ten > 0) {
                        ten--;
                        five--;
                    }
                    else five -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};