#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

void dfs(ll start, vvll& g, vll& vis){
    stack<ll> st;
    st.push(start);
    vis[start]=1;
    while(!st.empty()){
        ll u = st.top();st.pop();
        for(auto v : g[u]){
            if(!vis[v]){
                vis[v]=1;
                st.push(v);
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;

    vvll g(n+1), gr(n+1);
    rep(i,0,m){
        ll a,b;cin>>a>>b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    vll vis(n+1,0);
    dfs(1,g,vis);
    rep(i,1,n+1){
        if(!vis[i]){
            cout<<"NO\n"<<1<<' '<<i<<'\n';
            return 0;
        }
    }

    fill(vis.begin(),vis.end(),0);
    dfs(1,gr,vis);
    rep(i,1,n+1){
        if(!vis[i]){
            cout<<"NO\n"<<i<<' '<<1<<'\n';
            return 0;
        }
    }

    cout<<"YES\n";
    return 0;
}