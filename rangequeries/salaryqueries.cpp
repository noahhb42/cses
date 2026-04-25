#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mxn = 4e5+1;

struct Fenwick{
    ll n;
    ll tree[mxn];
    Fenwick(ll sz): n(sz){
        memset(tree,0,sizeof(tree));
    }

    ll sum(ll k){
        ll s = 0;
        while(k >= 1){
            s += tree[k];
            k -= k&-k;
        }
        return s;
    }

    void add(ll k, ll x){
        while(k<=n){
            tree[k] += x;
            k += k&-k;
        }
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll n,q;cin>>n>>q;
    ll a[n];
    vll vals;
    ll ind = 0;
    for(auto &i : a){cin>>i;vals.push_back(i);}
    vector<array<ll,3>> qs;
    rep(i,0,q){
        char c; ll x,y;cin>>c>>x>>y;
        qs.push_back({c=='?',x,y});
        if(c=='!'){
            vals.push_back(y);
        }
    }

    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());

    Fenwick f(vals.size());
    
    map<ll,ll> idxs;
    rep(i,0,vals.size()){
        idxs[vals[i]]=i+1;
    }

    for(auto &i : a)f.add(idxs[i],1);

    for(auto q : qs){
        if(q[0]==0){
            f.add(idxs[a[q[1]-1]],-1);
            f.add(idxs[q[2]],1);
            a[q[1]-1] = q[2];
        }
        else{
            ll l = lower_bound(vals.begin(),vals.end(),q[1])-vals.begin()+1;
            ll r = upper_bound(vals.begin(),vals.end(),q[2])-vals.begin();
            cout << f.sum(r)-f.sum(l-1) << '\n';
        }
    }
}