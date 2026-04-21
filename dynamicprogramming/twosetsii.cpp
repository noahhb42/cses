#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mod = (ll)1e9+7;
ll dp[501][500*501/2+1];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    rep(i,0,501){
        rep(j,0,500*501/2+1){
            dp[i][j]=0;
        }
    }

    dp[0][0] = 1;
    rep(i,1,501){
        rep(j,0,i*(i+1)/2+1){
            dp[i][j] += dp[i-1][j];
            if(i <= j){
                dp[i][j] += dp[i-1][j-i];
            }
            dp[i][j] %= mod;
        }
    }

    ll n;cin>>n;
    if(n%4 == 1 || n%4 == 2){
        cout << 0 << "\n";
        return 0;
    }

    cout << (dp[n][n*(n+1)/4]*((ll)5e8+4))%mod << "\n";
}