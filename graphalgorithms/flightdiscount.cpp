#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = 1e18;

vll dijkstra(ll n, vector<vector<pll>>& grid, ll s){
    vll d(n+1, INF);
    priority_queue<pll> pq;
    d[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        auto [du, u] = pq.top();pq.pop();
        if(-du != d[u])continue;
        for(auto [v, w] : grid[u]){
            ll nd = -du+w;
            if(nd < d[v]){
                d[v] = nd;
                pq.push({-nd, v});
            }
        }
    }
    return d;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;

    vector<vector<pll>> g(n+1), gr(n+1);
    vll A(m), B(m), W(m);
    rep(i,0,m){
        ll a,b,c;cin>>a>>b>>c;
        A[i]=a;B[i]=b;W[i]=c;
        g[a].push_back({b,c});
        gr[b].push_back({a,c});
    }

    auto d1 = dijkstra(n, g, 1);
    auto dn = dijkstra(n, gr, n);

    ll ans = INF;
    rep(i,0,m){
        ll u = A[i], v = B[i];
        if(d1[u]==INF || dn[v]==INF)continue;
        ans = min(ans, d1[u] + (W[i]/2) + dn[v]);
    }
    cout<<ans<<"\n";
}