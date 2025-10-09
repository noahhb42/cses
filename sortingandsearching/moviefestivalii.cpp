#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,k;cin>>n>>k;
    vector<array<ll,2>> mv(n);
    rep(i,0,n)cin>>mv[i][0]>>mv[i][1];
    sort(mv.begin(),mv.end(),[](auto &x, auto &y){
        if(x[1] != y[1])return x[1]<y[1];
        return x[0]<y[0];
    });

    multiset<ll> free_at{};
    rep(i,0,k)free_at.insert(0);

    ll ans = 0;
    for(auto &[a,b] : mv){
        auto it = free_at.upper_bound(a);
        if(it == free_at.begin())continue;
        --it;
        free_at.erase(it);
        free_at.insert(b);
        ++ans;
    }
    cout<<ans<<"\n";
    return 0;
}