#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mod = 1e9+7;
const ll inf = 1e18;

void solve(vector<vector<array<ll,2>>>& grid, ll n){
    vll dis(n+1,inf);
    vll nr(n+1,0);
    vll mn(n+1,inf);
    vll mx(n+1, 0);
    vll vis(n+1,0);
    dis[1]=0;
    nr[1]=1;
    mn[1]=0;
    priority_queue<array<ll,2>> pq;pq.push({0,1});
    while(!pq.empty()){
        auto [dist, u] = pq.top();pq.pop();
        if(-dist != dis[u])continue;

        for(auto [v,w] : grid[u]){
            ll nd = -dist + w;
            if(nd<dis[v]){
                dis[v] = nd;
                nr[v] = nr[u];
                mn[v] = mn[u]+1;
                mx[v] = mx[u]+1;
                pq.push({-nd, v});
                continue;
            }
            else if(nd==dis[v]){
                nr[v] += nr[u];
                nr[v]%=mod;
                mn[v] = min(mn[v],mn[u]+1);
                mx[v] = max(mx[v],mx[u]+1);
            }
        }
    }
    cout<<dis[n]<<' '<<nr[n]<<' '<<mn[n]<<' '<<mx[n]<<'\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    vector<vector<array<ll,2>>> grid(n+1);
    rep(_,0,m){ll a,b,c;cin>>a>>b>>c;grid[a].push_back({b,c});}

    solve(grid, n);
}