#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,k;cin>>n>>k;
    vll t(n);
    rep(i,0,n)cin>>t[i];
    ll a = 0, b = 4e18;
    while(b-a>1){
        ll m = (a+b)/2;
        ll sm = 0;
        for(auto i : t){
            sm+=m/i;
            if(sm>=k)break;
        }
        if(sm>=k){
            b = m;
        }
        else{
            a = m;
        }
    }
    cout<<b<<"\n";
}