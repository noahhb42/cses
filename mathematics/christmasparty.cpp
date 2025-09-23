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

    vll fact(n+1), invfact(n+1);

    fact[0]=1;
    for(ll i = 1 ; i<=n ; ++i){
        fact[i] = fact[i-1] * i % mod;
    }
    invfact[n] = powmod(fact[n],mod-2);
    for(ll i = n-1 ; i>=0 ; i--){
        invfact[i] = invfact[i+1] * (i+1) % mod;
    }

    ll ans = fact[n];
    ll sm = 0;
    rep(i,0,n+1){
        sm = (sm+(1-2*(i%2))*invfact[i]) % mod;
    }
    ans = ((ans*sm) % mod + mod) % mod;

    cout << ans << "\n";

}