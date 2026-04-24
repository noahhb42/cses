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

    void add(ll k, ll x){
        k+=n;
        tree[k]+=x;
        for(k /= 2 ; k>=1 ; k /= 2){
            tree[k] = tree[2*k] + tree[2*k+1];
        }
    }

    ll query(ll k){
        ll i = 1;
        while(i<n){
            if(tree[2*i] >= k)i*=2;
            else{
                k-=tree[2*i];
                i = 2*i+1;
            }
        }
        ll id = i-n;
        add(id,-1);
        return id;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll n;cin>>n;
    SegTree st(n);
    vll val(n);
    rep(i,0,n)cin>>val[i];
    rep(i,0,n)st.add(i,1);
    cout<<"\n";
    rep(i,0,n){
        ll a;cin>>a;
        cout << val[st.query(a)] << " ";
    }
    cout<<"\n";
}