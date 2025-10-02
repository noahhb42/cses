#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mod = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    vvll grid(n+1);
    vll indeg(n+1,0);
    rep(_,0,m){
        ll a,b;cin>>a>>b;
        grid[a].push_back(b);
        indeg[b]++;
    }

    vll topo(0);
    queue<ll> q;

    rep(i,0,n)if(indeg[i]==0)q.push(i);
    while(!q.empty()){
        ll u = q.front();q.pop();
        topo.push_back(u);
        for(auto v : grid[u])if(--indeg[v]==0)q.push(v);
    }

    vll dis(n+1,0);
    dis[1]=1;

    for(auto u : topo){
        for(auto v : grid[u]){
            dis[v]+=dis[u];
            if(dis[v]>=mod)dis[v]-=mod;
        }
    }

    cout<<dis[n]<<'\n';

}