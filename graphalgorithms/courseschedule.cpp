#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;

    vvll g(n+1);
    vll indeg(n+1, 0);
    rep(_,0,m){
        ll a,b;cin>>a>>b;
        g[a].push_back(b);
        ++indeg[b];
    }

    queue<ll> q;
    rep(i,1,n+1)if(indeg[i]==0)q.push(i);

    vll order(0);
    while(!q.empty()){
        ll u = q.front();q.pop();
        order.push_back(u);
        for(auto i : g[u])if(--indeg[i]==0)q.push(i);
    }

    if(order.size() != n){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for(auto i : order)cout<<i<<' ';cout<<"\n";
}