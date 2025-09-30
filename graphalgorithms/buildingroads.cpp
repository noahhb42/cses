#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mxn = 1e6;
vll parent(mxn);

ll find(ll a){
    if(a == parent[a])return a;
    return parent[a] = find(parent[a]);
}

void Union(ll a, ll b){
    ll pa = find(a);
    ll pb = find(b);
    parent[pa] = pb;
}

int main(){
    rep(i,0,mxn)parent[i]=i;
    ll n,m;cin>>n>>m;
    rep(i,0,m){
        ll a,b;cin>>a>>b;a--;b--;
        Union(a,b);
    }
    ll sm = 0;
    vector<array<ll,2>> roads(0);
    rep(i,1,n){
        if(find(0)==find(i))continue;
        roads.push_back({1,i+1});
        sm++;
        Union(0,i);
    }
    cout<<sm<<endl;
    if(roads.size()){
        for(auto [x,y] : roads){
            cout<<x<<" "<<y<<endl;
        }
    }
}