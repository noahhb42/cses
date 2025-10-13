#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

constexpr ll mxn = 1e5+1;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,x;cin>>n>>x;
    vll p(n), s(n), dp(mxn, 0);
    for(auto &y : p)cin>>y;
    for(auto &y : s)cin>>y;

    rep(i,0,n){
        ll bp = p[i], bs = s[i];
        for(ll c = x ; c>=bp ; --c){
            dp[c] = max(dp[c], dp[c-bp]+bs);
        }
    }
    ll ans = 0;
    rep(i,0,x+1){
        ans = max(ans, dp[i]);
    }
    cout<<ans<<"\n";
}