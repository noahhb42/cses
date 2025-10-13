#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

constexpr ll mxn = 1e6+1;
constexpr ll MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,x;cin>>n>>x;
    set<ll> s;
    vll dp(mxn, 0);
    rep(i,0,n){
        ll a;cin>>a;
        s.insert(a);
    }
    for(auto &c : s){
        dp[c]++;
        for(ll i = c+1 ; i<mxn ; ++i){
            dp[i] += dp[i-c];
            dp[i] %= MOD;
        }
    }
    cout<<dp[x]<<"\n";
}