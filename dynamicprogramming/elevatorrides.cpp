#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,x;cin>>n>>x;
    vll w(n);
    rep(i,0,n)cin>>w[i];

    vector<pair<ll,ll>> dp(1 << n,{n+1,0});
    dp[0] = {1,0};
    rep(mask,0,1<<n){
        rep(i,0,n){
            if(mask & (1<<i))continue;

            auto [rides, last] = dp[mask];

            pair<ll,ll> cand;

            if(last+w[i]<=x){
                cand = {rides, last+w[i]};
            }
            else{
                cand = {rides+1, w[i]};
            }

            ll newmask = mask | (1<<i);
            dp[newmask] = min(dp[newmask], cand);
        }
    }

    cout << dp[(1<<n)-1].first << "\n";
}