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
    vll k(n+1);
    rep(i,1,n+1)cin>>k[i];
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
        stack<ll> st;st.push(s);
        it[s]=0;vis[s]=1;
        while(!st.empty()){
            ll u = st.top();
            if(it[u]<g[u].size()){
                ll v = g[u][it[u]++];
                if(vis[v])continue;
                vis[v]=1;it[v]=0;
                st.push(v);
            }
            else{
                order.push_back(u);
                st.pop();
            }
        }
    }

    vll comp(n+1,-1);
    ll cid = 0;
    vis.assign(n+1,0);
    for(ll i = n-1 ; i>=0 ; --i){
        ll s = order[i];
        if(vis[s])continue;
        stack<ll> st;st.push(s);
        vis[s]=1;comp[s]=cid;
        while(!st.empty()){
            ll u = st.top();st.pop();
            for(auto v : gr[u]){
                if(vis[v])continue;
                comp[v] = cid;
                vis[v]=1;
                st.push(v);
            }
        }
        ++cid;
    }

    vll w(cid, 0);
    rep(i,1,n+1)w[comp[i]]+=k[i];

    vvll dag(cid);
    vll indeg(cid,0);
    rep(u,1,n+1){
        for(auto v : g[u]){
            ll cu = comp[u], cv = comp[v];
            if(cu!=cv){dag[cu].push_back(cv);++indeg[cv];}
        }
    }

    queue<ll> q;
    vll dp(cid, -1);
    rep(i,0,cid)if(indeg[i]==0){q.push(i);dp[i]=w[i];}

    ll ans = 0;
    while(!q.empty()){
        ll u = q.front();q.pop();
        ans = max(ans, dp[u]);
        for(auto v : dag[u]){
            if(dp[v]<dp[u]+w[v])dp[v]=dp[u]+w[v];
            if(--indeg[v]==0)q.push(v);
        }
    }

    cout<<ans<<"\n";
    return 0;
}