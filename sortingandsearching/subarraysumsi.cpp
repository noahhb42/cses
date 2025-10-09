#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,x;cin>>n>>x;
    vll a(n);
    rep(i,0,n)cin>>a[i];
    int l = 0, r = 0;
    ll sm = a[0];
    ll ans = 0;
    while(l<n && r<n){
        if(sm==x){
            ans++;
            if(l==r){
                sm-=a[l];
                l++;r++;
                if(l<n)sm+=a[l];
            }
            else{
                sm-=a[l];
                l++;
            }
        }
        else if(sm<x){
            r++;
            if(r<n)sm+=a[r];
        }
        else{
            if(l==r){
                sm-=a[l];
                l++;r++;
                if(l<n)sm+=a[l];
            }
            else{
                sm-=a[l];
                l++;
            }
        }
    }
    cout<<ans<<"\n";
}