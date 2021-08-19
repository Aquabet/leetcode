#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
class Solution {
public:
    string reverseVowels(string s) {
        int len = s.length();
        int i = 0;
        int j = len - 1;
        while(i < j) {
            while(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && 
                  s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && 
                  s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U' && i < len - 1) {
                i++;
            }
            while(s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && 
                  s[j] != 'o' && s[j] != 'u' && s[j] != 'A' && 
                  s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U' && j > 0) {
                j--;
            }
            if(i >= j) break;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};