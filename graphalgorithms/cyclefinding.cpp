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
    rep(i,0,m){
        ll a,b,w;cin>>a>>b>>w;
        E[i]={a,b,w};
    }

    vll dist(n+1,0),parent(n+1,-1); 

    ll x = -1;
    rep(_,1,n+1){
        x = -1;
        for(auto &e : E){
            if(dist[e.a]+e.w<dist[e.b]){
                dist[e.b] = dist[e.a]+e.w;
                parent[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if(x==-1){
        cout<<"NO"<<'\n';
        return 0;
    }

    ll y = x;
    rep(_,0,n)y=parent[y];

    vll cyc;
    ll v = y;
    cyc.push_back(v);
    v = parent[v];
    while(v != y){
        cyc.push_back(v);
        v = parent[v];
    }
    cyc.push_back(v);
    reverse(cyc.begin(),cyc.end());

    cout<<"YES\n";
    for(auto i : cyc)cout<<i<<' ';cout<<'\n';
}