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
    ll n,m;cin>>n>>m;

    vll fact(n+m+1), invfact(n+m+1);

    fact[0]=1;
    for(ll i = 1 ; i<=n+m ; ++i){
        fact[i] = fact[i-1] * i % mod;
    }
    invfact[n+m] = powmod(fact[n+m],mod-2);
    for(ll i = n+m-1 ; i>=0 ; i--){
        invfact[i] = invfact[i+1] * (i+1) % mod;
    }

    auto nCr = [&](ll a, ll b) -> ll{
        return fact[a] * invfact[b] % mod * invfact[a-b] % mod;
    };

    cout<<nCr(m+n-1,n-1)<<"\n";

}