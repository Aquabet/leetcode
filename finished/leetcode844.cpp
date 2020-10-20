#include<string>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int m = 0,n = 0;
        for(int i = 0; i<S.length();i++){
            if(S[i]=='#'){
                m--;
                if(m<0) m=0;
            }
            else{
                S[m]=S[i];
                m++;
            }
        }
        for(int i = 0; i<T.length();i++){
            if(T[i]=='#'){
                n--;
                if(n<0) n=0;
            }
            else{
                T[n]=T[i];
                n++;
            }
        }
//        cout<<S<<m<<" "<<T<<n<<endl;
        if(m!=n) return false;
        for(int i = 0;i<max(m,n);i++){
            if(T[i]!=S[i]) return false;
        }
        return true;
    }
};