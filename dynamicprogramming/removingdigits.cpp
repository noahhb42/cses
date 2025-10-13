#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

constexpr ll mxn = 1e6+1;
constexpr ll INF = 4e18;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vll dp(mxn,INF);
    dp[0]=0;
    rep(i,1,mxn){
        ll x = i;
        while(x){
            ll y = i-x%10;
            x/=10;
            if(y<0)continue;
            dp[i] = min(dp[i],dp[y]+1);
        }
    }
    ll n;cin>>n;
    cout<<dp[n]<<"\n";
}