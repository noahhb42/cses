#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mxn = 1e5+1;
ll parent[mxn];
ll depth[mxn];
ll sz[mxn];

ll find(ll a){
    if(parent[a]==a)return a;
    return parent[a]=find(parent[a]);
}

void Union(ll a, ll b){
    ll pa = find(a);
    ll pb = find(b);
    if(depth[pb]<depth[pa]){
        parent[pb]=pa;
        sz[pa]+=sz[pb];
    }
    else{
        parent[pa]=pb;
        sz[pb]+=sz[pa];
        if(depth[pa]==depth[pb])depth[pb]++;
    }
}

void sim(vector<array<ll,2>>& edges, ll n){
    ll nr = n; ll mx = 1;
    for(auto [a,b] : edges){
        if(find(a)==find(b)){
            cout<<nr<<" "<<mx<<'\n';
        }
        else{
            Union(a,b);
            nr--;
            mx = max(mx, max(sz[find(a)], sz[find(b)]));
            cout<<nr<<" "<<mx<<'\n';
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    rep(i,0,mxn){parent[i]=i;depth[i]=0;sz[i]=1;}
    ll n,m;cin>>n>>m;
    vector<array<ll,2>> edges;
    rep(_,0,m){
        ll a,b;cin>>a>>b;
        edges.push_back({a,b});
    }
    sim(edges,n);
}