#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,k;cin>>n>>k;
    vll p(k);
    rep(i,0,k)cin>>p[i];
    vector<bool> ans(n+1,false);
    rep(i,1,n+1){
        for(int mv : p){
            if(mv <= i && !ans[i-mv]){ans[i]=true;break;}
        }
    }
    rep(i,1,n+1){
        cout<<(ans[i] ? 'W' : 'L');
    }
    cout<<"\n";
}
