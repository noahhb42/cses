#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(int i = a ; i<n ; ++i)

const ll mod = 1'000'000'007;

ll powmod(ll base, ll exp){
    ll res = 1;
    while(exp){
        if(exp & 1) res = (res*base)%mod;
        base = (base*base) % mod;
        exp >>= 1;
    }
    return res;
}

int main(){
    ll n;cin>>n;    

    vector<array<ll,2>> q(n);
    ll maxA = 0;
    rep(i,0,n){
        ll a,b;cin>>a>>b;
        q[i] = {a,b};
        maxA = max(maxA, a);
    }

    vll fact(maxA+1), invfact(maxA+1);
    fact[0] = 1;
    for(ll i = 1 ; i<= maxA ; ++i){
        fact[i] = fact[i-1] * i % mod;
    }
    invfact[maxA] = powmod(fact[maxA], mod-2);
    for(ll i = maxA - 1 ; i>=0 ; --i){
        invfact[i] = invfact[i+1] * (i+1) % mod;
    }

    auto nCr = [&](ll a, ll b) -> ll{
        return fact[a] * invfact[b] % mod * invfact[a-b] % mod;
    };

    for(auto [a,b] : q){
        cout << nCr(a,b) << "\n";
    }
}