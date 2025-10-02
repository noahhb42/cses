#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,q;cin>>n>>q;
    
    ll LOG = 31;
    vvll up(LOG, vll(n+1));

    rep(i,1,n+1){
        cin>>up[0][i];
    }

    rep(j,1,LOG){
        rep(i,1,n+1){
            up[j][i]=up[j-1][up[j-1][i]];
        }
    }

    rep(i,0,q){
        ll x,k;cin>>x>>k;
        rep(l,0,LOG){
            if(k & (1<<l))x = up[l][x];
        }
        cout<<x<<"\n";
    }

}