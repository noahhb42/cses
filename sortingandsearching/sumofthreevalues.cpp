#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,x;cin>>n>>x;
    vector<array<ll,2>> a(n);
    rep(i,0,n){
        ll v;cin>>v;
        a[i] = {v,i+1};
    }
    sort(a.begin(), a.end());

    rep(i,0,n){
        ll l = i+1, r = n-1;
        ll need = x - a[i][0];
        while(l<r){
            ll s = a[l][0] + a[r][0];
            if(s==need){
                cout<<a[i][1]<<" "<<a[l][1]<<" "<<a[r][1]<<"\n";
                return 0;
            }
            if(s>need)r--;
            else l++;
        }
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}