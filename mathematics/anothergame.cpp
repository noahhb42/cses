#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

void solve(){
    ll n;cin>>n;
    bool all_even = true;
    rep(i,0,n){
        ll x;cin>>x;
        if(x&1)all_even = false;
    }
    cout<<(all_even ? "second\n" : "first\n");
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t;cin>>t;
    while(t--)solve();
}