#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(int a, int b) {
        int suma = 0;
        int sumb = 0;
        int c = a;
        int d = b;
        while(a != 0) {
            suma += a % 2;
            a /= 2;
        }
        while(b != 0) {
            sumb += b % 2;
            b /= 2;
        }
        if(suma == sumb) return c < d;
        return suma < sumb;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};