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

    vector<vector<array<ll,2>>> g(n+1);
    vvll und(n+1);
    vll indeg(n+1,0), outdeg(n+1,0);
    vector<array<ll,2>> edges(m);
    rep(i,0,m){
        ll a,b;cin>>a>>b;
        edges[i]={a,b};
        g[a].push_back({b,i});
        outdeg[a]++;indeg[b]++;
        und[a].push_back(b);
        und[b].push_back(a);
    }

    bool ok = true;
    rep(v,1,n+1){
        if(v==1)ok &= (outdeg[v] == indeg[v]+1);
        else if(v==n)ok &= (indeg[v] == outdeg[v]+1);
        else ok &= (outdeg[v]==indeg[v]);
    }
    if(!ok){cout<<"IMPOSSIBLE\n";return 0;}

    vll vis(n+1,0);

    stack<ll> st;
    st.push(1);
    vis[1]=1;
    while(!st.empty()){
        ll u = st.top(); st.pop();
        for(auto v : und[u]){
            if(!vis[v]){vis[v]=1;st.push(v);}
        }
    }
    rep(v,1,n+1)if((outdeg[v]+indeg[v])>0 && !vis[v]){cout<<"IMPOSSIBLE\n";return 0;}

    vll it(n+1, 0);
    vll used(m,0);
    vll path(0);
    st.push(1);
    while(!st.empty()){
        ll u = st.top();
        auto &adj = g[u];
        while(it[u]<adj.size() && used[adj[it[u]][1]])++it[u];
        if(it[u]==adj.size()){
            path.push_back(u);
            st.pop();
        }
        else{
            auto [v, id] = adj[it[u]];
            used[id] = 1;
            st.push(v);
        }
    }
    reverse(path.begin(), path.end());

    if(path.size() != m+1 || path[0] != 1 || path[path.size()-1] != n){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    for(auto i : path)cout<<i<<' ';cout<<'\n';
}