#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    vll a(n);
    rep(i,0,n)cin>>a[i];
    ll mx = -4e18;
    ll sm = 0;
    rep(i,0,n){
        sm+=a[i];
        mx = max(mx, sm);
        if(sm<0)sm=0;
    }
    cout<<mx<<"\n";
}