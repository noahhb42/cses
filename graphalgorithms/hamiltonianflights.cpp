#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll MOD = 1e9 + 7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    vll prevmask(n,0);
    vvll cnt(n, vll(n,0));
    rep(i,0,m){
        ll a,b;cin>>a>>b;
        a--;b--;
        cnt[a][b]++;
        prevmask[b] |= (1<<a);
    }

    ll FULL = (1<<n)-1;
    vvll dp(1<<n, vll(n,0));
    dp[1][0]=1;

    rep(mask,1,FULL+1){
        if((mask&1)==0)continue;
        if((mask&(1<<(n-1))) && mask != FULL)continue;

        rep(v,0,n)if(mask & (1<<v)){
            if(mask == (1<<v))continue;
            ll pm = prevmask[v] & (mask ^(1<<v));
            ll ways = 0;    
            for(ll s = pm ; s ; s &= s-1){
                ll u = __builtin_ctz(s);
                ways += dp[mask ^ (1<<v)][u]*cnt[u][v] % MOD;
                if(ways>=MOD)ways-=MOD;
            }
            dp[mask][v] += ways;
            if(dp[mask][v]>=MOD)dp[mask][v]-=MOD;
        }
    }

    cout<<dp[FULL][n-1]<<"\n";
    return 0;
}