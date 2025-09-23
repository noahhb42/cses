#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mxn = 1e6+1;
vll nr(mxn,0);

void fill(){
    for(ll i=1 ; i<=mxn ; ++i){
        for(ll j=i ; j<=mxn ; j+=i){
            nr[j]++;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fill();
    ll n;cin>>n;
    rep(i,0,n){
        ll a;cin>>a;
        cout<<nr[a]<<"\n";
    }
}