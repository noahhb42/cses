#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = (ll)1e18;

struct SegTree{
    ll n;
    vector<array<ll,4>> tree;

    SegTree(ll sz){
        n = 1;
        while(n<sz)n<<=1;
        tree.assign(2*n,{-INF,-INF,-INF,-INF});
    }

    void insert(ll k, ll x){
        k += n;
        tree[k] = {x,x,x,x};
        for(k /= 2 ; k >= 1 ; k /= 2){
            auto &l = tree[2*k];
            auto &r = tree[2*k+1];
            tree[k] = {
                l[0]+r[0],
                max(l[1], l[0]+r[1]),
                max(l[3]+r[1], max(l[2], r[2])),
                max(r[3], l[3]+r[0])
            };
        }
    }

    ll max_subarray(){
        return tree[1][2];
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll n,q;cin>>n>>q;
    SegTree st(n);
    rep(i,0,n){
        ll a;cin>>a;
        st.insert(i,a);
    }

    rep(i,0,q){
        ll a,b;cin>>a>>b;
        st.insert(a-1,b);
        cout << max(0LL,st.max_subarray()) << "\n";
    }
}