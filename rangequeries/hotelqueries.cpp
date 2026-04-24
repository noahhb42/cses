#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct SegTree{
    ll n;
    vll tree;
    SegTree(ll sz){
        n = 1;
        while(n < sz)n*=2;
        tree.assign(2*n,0);
    }

    void update(ll k, ll x){
        k+=n;
        tree[k] = x;
        for(k /= 2 ; k>=1 ; k /= 2){
            tree[k] = max(tree[2*k], tree[2*k+1]);
        }
    }

    ll query(ll r){
        ll i = 1;
        if(tree[i] < r)return 0;
        while(i < n){
            if(tree[2*i]>=r)i*=2;
            else i=2*i+1;
        }
        ll id = i-n;
        update(id,tree[i]-r);
        return id+1;
    }

};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll n,r;cin>>n>>r;
    SegTree st(n);
    rep(i,0,n){
        ll a;cin>>a;
        st.update(i,a);
    }
    rep(i,0,r){
        ll a;cin>>a;
        cout << st.query(a) << " ";
    }
    cout << "\n";
}