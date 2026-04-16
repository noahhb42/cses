#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    ll n;cin>>n;
    vvll ans(n, vll(n,201));
    vll pos(202,0);
    rep(i,0,n){
        rep(j,0,n){
            fill(pos.begin(),pos.end(),0);
            rep(k,0,i){
                pos[ans[k][j]]=1;
            }
            rep(k,0,j){
                pos[ans[i][k]]=1;
            }
            rep(k,0,201){
                if(pos[k]==0){
                    ans[i][j] = k;
                    break;
                }
            }
        }
    }
    rep(i,0,n){
        rep(j,0,n){
            cout << ans[i][j] << (j==n-1 ? '\n' : ' ');
        }
    }
}