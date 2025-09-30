#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

void bfs(vvll& grid, vll& vis){
    vis[0]=0;
    queue<ll> q;
    q.push(0);
    while(q.size()){
        ll cur = q.front();q.pop();
        for(auto n : grid[cur]){
            if(vis[n]!=-1)continue;
            q.push(n);
            vis[n]=cur;
        }
    }
}

int main(){
    ll n,m;cin>>n>>m;
    vvll grid(n, vll(0));
    vll vis(n,-1);
    rep(i,0,m){
        ll a,b;cin>>a>>b;a--;b--;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    bfs(grid, vis);
    if(vis[n-1]==-1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vll route(0);
    route.push_back(n-1);
    ll cur = n-1;
    while(vis[cur]!=cur){
        cur = vis[cur];
        route.push_back(cur);
    }
    cout<<route.size()<<'\n';
    reverse(route.begin(),route.end());
    for(auto i : route)cout<<i+1<<' ';
    cout<<'\n';
}