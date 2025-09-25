#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mod = 1e9+7;

ll powmod(ll a,ll b){
    ll r = 1;
    a%=mod;
    b%=mod-1;
    while(b){
        if(b&1){
            r = (r*a)%mod;
        }
        a = (a*a)%mod;
        b>>=1;
    }
    return r;
}

ll inv(ll a){return powmod(a,mod-2);}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    vector<vll> mat(n, vll(m));
    rep(i,0,n)rep(j,0,m+1)cin>>mat[i][j];
}