#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    ll sm = 0;
    vll a(n);
    rep(i,0,n){
        cin>>a[i];
        ll b;cin>>b;sm+=b;
    }
    sort(a.begin(),a.end());
    ll time = 0;
    for(auto i : a){
        time+=i;
        sm-=time;
    }
    cout<<sm<<"\n";
}