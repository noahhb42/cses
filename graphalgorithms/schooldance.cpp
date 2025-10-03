#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
typedef array<ll,4> qll;
#define rep(i,a,n) for(int i = a ; i<n ; ++i)

struct HopcroftKarp{
    ll nL, nR;
    vvll adj;
    vll dist, pairU, pairV;
    const ll INF = 1e18;

    HopcroftKarp(ll nL, ll nR): nL(nL), nR(nR), adj(nL+1), dist(nL+1), pairU(nL+1, 0), pairV(nR+1, 0){}

    void addEdge(ll u, ll v){
        adj[u].push_back(v);
    }

    bool bfs(){
        queue<ll> q;
        rep(u,1,nL+1){
            if(pairU[u]==0){dist[u]=0;q.push(u);}
            else dist[u]=INF;
        }
        ll distNIL = INF;
        while(!q.empty()){
            ll u = q.front(); q.pop();
            if(dist[u] < distNIL){
                for(auto v : adj[u]){
                    ll pu = pairV[v];
                    if(pu==0){
                        distNIL=dist[u]+1;
                    }
                    else if(dist[pu]==INF){
                        dist[pu] = dist[u]+1;
                        q.push(pu);
                    }
                }
            }
        }
        return distNIL != INF;
    }

    bool dfs(ll u){
        for(auto v : adj[u]){
            ll pu = pairV[v];
            if(pu == 0 || (dist[pu]==dist[u]+1 && dfs(pu))){
                pairU[u]=v;
                pairV[v]=u;
                return true;
            }
        }
        dist[u]=INF;
        return false;
    }

    ll maxMatching(){
        ll matching = 0;
        while(bfs()){
            rep(u,1,nL+1){
                if(pairU[u]==0 && dfs(u)){
                    ++matching;
                }
            }
        }
        return matching;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,k;cin>>n>>m>>k;
    HopcroftKarp hk(n+1,m+1);

    rep(i,0,k){
        ll a,b;cin>>a>>b;
        hk.addEdge(a,b);
    }

    cout<<hk.maxMatching()<<'\n';
    rep(i,1,n+1){
        ll v = hk.pairU[i];
        if(v==0)continue;
        cout<<i<<' '<<v<<'\n';
    }
}