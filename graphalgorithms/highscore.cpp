#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = 1e18;

struct Edge{
    ll a,b,w;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    vector<Edge> E(m);
    vvll rev(n+1);
    rep(i,0,m){
        ll a,b,w;cin>>a>>b>>w;
        E[i]={a,b,w};
        rev[b].push_back(a);
    }

    vll d(n+1, INF);
    d[1] = 0;
    rep(i,1,n){
        bool any = false;
        for(auto &e : E){
            if(d[e.a]==INF)continue;
            ll nd = d[e.a]-e.w;
            if(nd < d[e.b]){d[e.b]=nd;any=true;}
        }
        if(!any)break;
    }

    vector<bool> bad(n+1, false);
    for(auto &e : E){
        if(d[e.a]==INF)continue;
        if(d[e.a]-e.w < d[e.b])bad[e.b]=true;
    }

    vector<bool> canReach(n+1, false);
    queue<ll> q;
    q.push(n);canReach[n]=true;
    while(!q.empty()){
        ll u = q.front();q.pop();
        for(ll v : rev[u])if(!canReach[v]){
            canReach[v]=true;
            q.push(v);
        }
    }

    for(ll v = 1 ; v<=n ; ++v){
        if(bad[v] && canReach[v]){
            cout<<-1<<'\n';
            return 0;
        }
    }

    cout<<-d[n]<<'\n';
}