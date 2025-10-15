#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

constexpr ll mxn = 1e6+1;
constexpr ll MOD = 1e9+7;
ll dp[mxn], a[mxn], b[mxn];

void fill(){
    a[1] = 1; b[1] = 1; dp[1] = 2;
    rep(n,2,mxn){
        a[n] = (2*a[n-1]+b[n-1]) % MOD;
        b[n] = (a[n-1]+4*b[n-1]) % MOD;
        dp[n] = (a[n] + b[n]) % MOD;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fill();
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        cout<<dp[n]<<"\n";
    }
}