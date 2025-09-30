#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<array<ll,2>>> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = 1e18;

void dijkstra(vvll& grid, vll& dis){
    priority_queue<array<ll,2>> pq;
    pq.push({0,0});
    while(pq.size()){
        auto [dist, node] = pq.top(); pq.pop();
        if(dis[node]<INF)continue;
        dis[node] = -dist;
        for(auto [new_node, new_dist] : grid[node]){
            if(dis[new_node]<INF)continue;
            pq.push({dist-new_dist, new_node});
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    vvll grid(n, vector<array<ll,2>>(0));
    vll dis(n,INF);
    rep(i,0,m){
        ll a,b,c;cin>>a>>b>>c;
        a--;b--;
        grid[a].push_back({b,c});
    }
    dijkstra(grid, dis);
    for(auto i : dis)cout<<i<<' ';cout<<'\n';
}