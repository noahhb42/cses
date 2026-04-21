#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mxn = (ll)2e5+1;
const ll INF = (ll)1e10;
ll dp[mxn];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    fill(dp,dp+mxn,INF);

    ll n;cin>>n;
    vll a(n);
    for(auto &i : a)cin>>i;

    for(auto i : a){
        dp[lower_bound(dp,dp+mxn,i)-dp]=i;
    }
    ll val = lower_bound(dp,dp+mxn,INF)-dp;

    cout << val << "\n";
}