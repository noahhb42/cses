#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

ll sm(vll& a, ll i, ll j){
    return a[j]-a[i-1];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;cin>>n;
    vll p(n+1);
    p[0]=0;
    rep(i,1,n+1){
        cin>>p[i];
        p[i]+=p[i-1];
    }

    vvll dp(n+1,vll(n+1,LLONG_MAX));
    rep(i,0,n+1)dp[i][i]=sm(p,i,i);

    rep(i,1,n){
        rep(j,1,n+1-i){
            ll s = j;
            ll e = j+i;
            ll v1 = sm(p,s,s) + sm(p,s+1,e) - dp[s+1][e];
            ll v2 = sm(p,e,e) + sm(p,s,e-1) - dp[s][e-1];
            dp[s][e] = max(v1,v2);
        }
    }

    cout << dp[1][n] << endl;
}