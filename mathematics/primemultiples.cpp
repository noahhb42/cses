#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,k;cin>>n>>k;
    vll a(k);
    rep(i,0,k)cin>>a[i];

    ll ans = 0;
    ll total = 1<<k;

    for(ll mask = 1 ; mask < total ; ++mask){
        __int128 prod = 1;
        bool big = false;
        for(ll i = 0 ; i<k ; ++i){
            if(mask & (1<<i)){
                prod *= (__int128)a[i];
                if(prod > (__int128)n){big = true;break;}
            }
        }
        if(big)continue;

        ll cnt = (ll)((__int128)n/prod);
        ll bits = __builtin_popcount((unsigned)mask);
        if (bits & 1){
            ans += cnt;
        }
        else{
            ans -= cnt;
        }
    }

    cout << ans << "\n";
}