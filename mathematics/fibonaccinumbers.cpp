#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mod = 1e9+7;

ll fib(ll n){
    ll a1 = 0, a2 = 1, a3 = 1, a4 = 1;
    ll r1 = 1, r2 = 0, r3 = 0, r4 = 1;
    ll t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    while(n){
        if(n&1){
            t1 = (r1*a1 + r2*a3) % mod;
            t2 = (r1*a2 + r2*a4) % mod;
            t3 = (r3*a1 + r4*a3) % mod;
            t4 = (r3*a2 + r4*a4) % mod;
            r1 = t1;r2 = t2;r3 = t3;r4 = t4;
        }
        t1 = (a1*a1 + a2*a3) % mod;
        t2 = (a1*a2 + a2*a4) % mod;
        t3 = (a3*a1 + a4*a3) % mod;
        t4 = (a3*a2 + a4*a4) % mod;
        a1 = t1;a2 = t2;a3 = t3;a4 = t4;
        n>>=1;
    }
    return r2;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    cout<<fib(n)<<endl;
}