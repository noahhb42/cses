#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mod = 1e9+7;

ll sum(ll l, ll r){
    __int128 L = l, R = r;
    __int128 len = R-L+1;
    __int128 s = L+R;
    if(len%2==0) len/=2;
    else s/=2;
    __int128 prod = ((len%mod)*(s%mod))%mod;
    return (ll)prod;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    ll ans = 0;
    for(ll i = 1 ; i<=n ; ){
        ll q = n/i;
        ll j = n/q;
        ll s = sum(i,j);
        ans = (ans + (ll)((__int128)(q%mod)*s % mod))%mod;
        i=j+1;
    }
    cout<<ans<<endl;
}