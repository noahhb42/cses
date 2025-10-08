#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    struct R{ll l,r;int id;};
    auto compare = [&](const R& A, const R& B){
        if(A.l != B.l)return A.l<B.l;
        return A.r>B.r;
    };
    int n;cin>>n;
    vector<R> a(n);
    rep(i,0,n){
        ll x,y;cin>>x>>y;
        a[i] = {x,y,(int)i};
    }
    sort(a.begin(), a.end(), compare);
    vector<int> contains(n,0), contained(n,0);
    ll prefMax = -4e18;
    rep(i,0,n){
        if(prefMax >= a[i].r)contained[a[i].id] = 1;
        prefMax = max(prefMax, a[i].r);
    }

    ll sufMin = 4e18;
    for(int i = n-1 ; i>=0 ; --i){
        if(sufMin <= a[i].r)contains[a[i].id] = 1;
        sufMin = min(sufMin, a[i].r);
    }
    for(auto i : contains)cout<<i<<" ";cout<<"\n";
    for(auto i : contained)cout<<i<<" ";cout<<"\n";
    return 0;
}