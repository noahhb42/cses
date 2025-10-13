#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    vvll dp(n,vll(m,0));
    vll a(n);
    for(auto &x : a){cin>>x;x--;}

    if(a[0]==-1){
        rep(i,0,m){dp[0][i] = 1;}
    }
    else{
        dp[0][a[0]]=1;
    }

    rep(i,1,n){
        if(a[i]==-1)rep(j,0,m){
            dp[i][j]+= dp[i-1][j] + (j+1<m ? dp[i-1][j+1] : 0) + (j-1>=0 ? dp[i-1][j-1] : 0);
            dp[i][j] %= MOD;
        }
        else{
            dp[i][a[i]] += dp[i-1][a[i]] + (a[i]+1<m ? dp[i-1][a[i]+1] : 0) + (a[i]-1>=0 ? dp[i-1][a[i]-1] : 0);
        }
    }

    ll ans = 0;
    if(a[n-1]==-1){
        rep(i,0,m)ans+=dp[n-1][i];
    }
    else ans += dp[n-1][a[n-1]];
    cout << ans % MOD << "\n";
}