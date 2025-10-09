#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    ll mx = 0;
    ll sm = 0;
    rep(i,0,n){
        ll a;cin>>a;
        sm+=a;
        mx=max(mx,a);
    }
    cout<<max(2*mx, sm)<<"\n";
    return 0;
}