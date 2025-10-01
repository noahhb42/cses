#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = 1e18;

vll dijkstra(ll n, vector<vector<pll>>& grid, ll k, vll& cnt){
    priority_queue<pll> pq;
    pq.push({0,1});

    vll ans(0);

    while(!pq.empty() && ans.size()<k){
        auto [d,u] = pq.top();pq.pop();
        if(cnt[u] >= k)continue;
        if(++cnt[u]>k)continue;

        if(u==n){
            ans.push_back(-d);
            if(ans.size()==k)break;
        }

        for(auto [v, w] : grid[u]){
            if(cnt[v]<k){
                pq.push({d-w, v});
            }
        }
    }

    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,k;cin>>n>>m>>k;

    vector<vector<pll>> g(n+1);
    rep(_,0,m){
        ll a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
    }

    vll cnt(n+1,0);

    vll ans = dijkstra(n, g, k, cnt);

    for(auto i : ans)cout<<i<<' ';cout<<'\n';
}