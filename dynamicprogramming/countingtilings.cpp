#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

ll n,m;
const ll MOD = (ll)1e9+7;

void generate_new_masks(ll row, ll curmask, ll nextmask, vll& nextmasks){
    if(row == n){
        nextmasks.push_back(nextmask);
        return;
    }

    if(curmask & (1<<row)){
        generate_new_masks(row+1, curmask, nextmask, nextmasks);
        return;
    }

    //Placing horizontal domino
    generate_new_masks(row+1, curmask, nextmask|(1<<row), nextmasks);

    //Placing vertical domino
    if(row+1 < n && !(curmask & (1<<(row+1)))){
        generate_new_masks(row+2, curmask, nextmask, nextmasks);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    if(n > m)swap(n,m);

    ll s = 1<<n;

    vvll trans(s);
    rep(mask,0,s){
        generate_new_masks(0,mask,0,trans[mask]);
    }

    vll dp(s,0), ndp(s,0);
    dp[0] = 1;
    rep(col,0,m){
        fill(ndp.begin(),ndp.end(),0);

        rep(mask,0,s){
            if(dp[mask]==0)continue;
            for(auto nextmask : trans[mask]){
                ndp[nextmask] += dp[mask];
                if(ndp[nextmask] >= MOD)ndp[nextmask]-=MOD;
            }
        }

        dp.swap(ndp);
    }

    cout << dp[0] << "\n";
}