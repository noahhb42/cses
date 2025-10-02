#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mxn = 1e5+1;
ll parent[mxn];
ll depth[mxn];

ll find(ll a){
    if(parent[a]==a)return a;
    return parent[a]=find(parent[a]);
}

void Union(ll a, ll b){
    ll pa = find(a);
    ll pb = find(b);
    if(depth[pb]<depth[pa]){
        parent[pb]=pa;
    }
    else{
        parent[pa]=pb;
        if(depth[pa]==depth[pb])depth[pb]++;
    }
}

ll mst(vector<array<ll,3>>& edges){
    ll sm = 0;
    for(auto [w,a,b] : edges){
        if(find(a)==find(b))continue;
        sm+=w;
        Union(a,b);
    }
    return sm;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    rep(i,0,mxn){parent[i]=i;depth[i]=1;}
    ll n,m;cin>>n>>m;
    vector<array<ll,3>> edges;
    rep(_,0,m){
        ll a,b,w;cin>>a>>b>>w;
        edges.push_back({w,a,b});
    }
    sort(edges.begin(),edges.end());
    ll mn = mst(edges);
    
    bool pos = true;
    ll par = find(1);
    rep(i,1,n+1)if(find(i)!=par)pos=false;

    if(!pos){cout<<"IMPOSSIBLE\n";return 0;}
    cout<<mn<<'\n';

}