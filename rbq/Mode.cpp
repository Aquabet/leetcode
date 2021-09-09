#include<bits/stdc++.h>
using namespace std;

#define LOCAL

#define PB push_back
#define PF push_front

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) {
    return b?gcd(b,a%b):a;
}

ll exgcd(ll l,ll r,ll &x,ll &y) {
    if(r == 0) {
        x = 1;
        y = 0;
        return l;
    } else {
        ll d = exgcd(r, l%r, y, x);
        y -= l/r*x;
        return d;
    }
}

ll MOD(ll a, ll m) {
    a %= m;
    if(a < 0)a += m;
    return a;
}
//乘法逆元
ll inverse(ll a, ll m) {
    a = MOD(a, m);
    if(a <= 1)return a;
    return MOD((1 - inverse(m, a) * m) / a, m);
}
//快速幂
ll kasumi(ll a, ll b, ll mod) {
    a %= mod;
    if(b < 0)a = inverse(a, mod), b = -b;
    ll ans = 1;
    while(b) {
        if(b & 1)ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans % mod;
}


class Solution {
public:

};

#ifdef LOCAL

int main() {
    freopen("testdata.in", "r", stdin);
}
#endif