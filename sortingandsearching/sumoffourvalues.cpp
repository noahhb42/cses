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

    unordered_map<ll, array<ll,2>> seen{};

    rep(i,0,n){
        rep(j,i+1,n){
            ll need = x-a[i]-a[j];
            auto it = seen.find(need);
            if(it != seen.end()){
                auto [p,q] = it->second;
                cout<<p+1<<" "<<q+1<<" "<<i+1<<" "<<j+1<<"\n";
                return 0;
            }
        }
        rep(k,0,i){
            seen[a[k]+a[i]]={k,i};
        }
    }

    cout<<"IMPOSSIBLE\n";
    return 0;
}