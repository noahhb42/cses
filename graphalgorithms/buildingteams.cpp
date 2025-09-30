#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

void bfs(vvll& grid, vll& vis){
    queue<ll> q;
    unordered_set<ll> s;
    rep(i,0,vis.size())s.insert(i);
    while(!s.empty()){
        vis[*s.begin()]=1;
        q.push(*s.begin());
        while(q.size()){
            ll cur = q.front();q.pop();s.erase(cur);
            for(auto n : grid[cur]){
                if(vis[n]==vis[cur]){vis[n]=3;return;}
                if(vis[n]!=-1)continue;
                q.push(n);
                vis[n]=vis[cur]^3;
            }
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
    for(auto i : vis){
        if(i==3){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    for(auto i : vis)cout<<i<<' ';
    cout<<'\n';
}