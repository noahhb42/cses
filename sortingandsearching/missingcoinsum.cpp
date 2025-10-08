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
    sort(a.begin(), a.end());
    ll need = 1;
    for(auto i : a){
        if(i<=need)need+=i;
        else{
            cout<<need<<"\n";
            return 0;
        }
    }
    cout<<need<<"\n";
    return 0;
}