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
    vll order(0);
    vll it(n+1,-1);

    rep(s,1,n+1)if(!vis[s]){
        stack<ll> st;
        st.push(s);
        vis[s]=1;
        it[s]=0;
        while(!st.empty()){
            ll u = st.top();
            if(it[u] < g[u].size()){
                ll v = g[u][it[u]++];
                if(!vis[v]){
                    vis[v]=1;
                    st.push(v);
                    it[v]=0;
                }
            }
            else{
                order.push_back(u);
                st.pop();
            }
        }
    }

    vll comp(n+1,0);
    ll cid = 0;
    vis.assign(n+1,0);
    for(ll i = n-1 ; i>=0 ; --i){
        ll s = order[i];
        if(vis[s])continue;
        ++cid;
        stack<ll> st;
        st.push(s);
        vis[s]=1;
        comp[s]=cid;
        while(!st.empty()){
            ll u = st.top();st.pop();
            for(auto v : gr[u])if(!vis[v]){
                vis[v] = 1;
                comp[v] = cid;
                st.push(v);
            }
        }
    }

    cout<<cid<<'\n';
    rep(i,1,n+1)cout<<comp[i]<<' ';cout<<'\n';
    return 0;
}