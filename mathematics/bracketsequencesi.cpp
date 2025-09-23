#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mod = 1e9+7;

ll powmod(ll a, ll b){
    ll r = 1;
    while(b){
        if(b & 1) r = (r*a)%mod;
        b>>=1;
        a = (a*a)%mod;
    }
    return r;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    if(n&1){cout<<"0\n";return 0;}

    vll fact(n+1), invfact(n+1);
    fact[0] = 1;
    rep(i,1,n+1){
        fact[i] = fact[i-1] * i % mod;
    }
    invfact[n] = powmod(fact[n],mod-2);
    for(ll i = n-1 ; i>=0 ; --i){
        invfact[i] = invfact[i+1] * (i+1) % mod;
    }

    cout << fact[n] * invfact[n/2] % mod * invfact[n/2] % mod * powmod(n/2+1,mod-2) % mod << "\n";
}