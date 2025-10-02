#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

void kahns(vvll& grid, vll& dis, vll& parent, vll& indeg, ll n){

    vll topo(0);
    queue<ll> q;
    rep(i,0,n)if(indeg[i]==0)q.push(i);
    while(!q.empty()){
        ll u = q.front();q.pop();
        topo.push_back(u);
        for(auto v : grid[u]){
            if(--indeg[v]==0)q.push(v);
        }
    }

    dis[1] = 1;parent[1] = 1;

    for(auto u : topo){
        if(dis[u]==-1)continue;
        for(auto v : grid[u]){
            if(dis[v]<dis[u]+1){
                dis[v] = dis[u]+1;
                parent[v] = u;
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    vvll grid(n+1);
    vll indeg(n+1,0);
    vll dis(n+1,-1);
    vll parent(n+1,-1);
    rep(_,0,m){
        ll a,b;cin>>a>>b;
        indeg[b]++;
        grid[a].push_back(b);
    }
    kahns(grid, dis, parent, indeg, n);

    if(dis[n]==-1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    vll path(0);

    for(int cur = n ; ; cur = parent[cur]){
        path.push_back(cur);
        if(cur==parent[cur])break;
    }

    reverse(path.begin(), path.end());

    cout<<dis[n]<<'\n';
    for(auto u : path)cout<<u<<' ';cout<<'\n';

}