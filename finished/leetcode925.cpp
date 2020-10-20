#include<string>
using namespace std;
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int length = typed.length();
        int j = 0 , i = 0;
        for(;i <= length;){
	        if(name[j]==typed[i]){
	            i++;j++;
            }
            else{
                if(i>0){
                    if(name[j]!=typed[i]&&typed[i]==typed[i-1]&&i>0&&i<=typed.length()&&j<=name.length()){
                        i++;
                    }
                    else{
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};