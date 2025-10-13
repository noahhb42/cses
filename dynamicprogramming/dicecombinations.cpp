#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll MOD = 1e9+7;
const ll mxn = 1e6+1;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vll dp(mxn,0);
    dp[1]=1;
    rep(i,2,mxn){
        ll s = 0;
        for(ll j = i-1 ; j>=max(0LL,i-6) ; --j){
            s+=dp[j];
        }
        if(i<=6)s++;
        dp[i] = s%MOD;
    }
    cout<<"\n";
    ll n;cin>>n;
    cout<<dp[n]<<"\n";
}