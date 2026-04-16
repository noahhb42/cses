#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    ll n;cin>>n;
    ll sm = 0;
    rep(i,0,n-1){
        ll a;cin>>a;
        sm+=a;
    }
    cout << n*(n+1)/2 - sm << "\n";
}