#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mxn = 1e6+1;
const ll INF = (ll)4e18;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vll dp(mxn,INF);
    ll n,x;cin>>n>>x;
    set<ll> s;
    rep(i,0,n){
        ll a;cin>>a;
        s.insert(a);
    }
    for(auto& i : s)dp[i]=1;
    rep(i,1,mxn){
        for(auto &j : s){
            if(i-j<0)break;
            dp[i]=min(dp[i],dp[i-j]+1);
        }
    }
    ll v = dp[x];
    cout<<(v==INF ? -1 : v)<<"\n";
}