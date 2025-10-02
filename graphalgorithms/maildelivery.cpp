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
    vector<vector<array<ll,2>>> g(n+1);
    vll deg(n+1,0);
    rep(i,0,m){
        ll a,b;cin>>a>>b;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
        ++deg[a];++deg[b];
    }

    rep(i,1,n+1){
        if(deg[i] & 1){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }

    vll vis(n+1,0);
    stack<ll> stc;
    stc.push(1);vis[1]=1;
    while(!stc.empty()){
        ll u = stc.top();stc.pop();
        for(auto [v,id] : g[u]){
            if(!vis[v]){
                vis[v] = 1;
                stc.push(v);
            }
        }
    }
    rep(v,1,n+1){
        if(deg[v]>0 && !vis[v]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    if(m>0 && deg[1]==0){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    vll it(n+1,0), used(m,0), path(0);
    stack<ll> st;st.push(1);
    while(!st.empty()){
        ll u = st.top();
        while(it[u] < g[u].size() && used[g[u][it[u]][1]])++it[u];
        if(it[u]==g[u].size()){
            path.push_back(u);
            st.pop();
        }
        else{
            auto [v,id] = g[u][it[u]++];
            if(!used[id]){
                used[id] = 1;
                st.push(v);
            }
        }
    }

    if(path.size() != m+1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for(auto u : path)cout<<u<<' ';cout<<'\n';
    return 0;
}
