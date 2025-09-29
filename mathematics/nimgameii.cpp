#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll nim = 0;
        rep(i,0,n){
            ll x;cin>>x;
            nim ^= (x%4);
        }
        cout << (nim!=0 ? "first" : "second") << "\n";
    }   
}
