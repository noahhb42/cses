#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = (ll)4e18;

struct SegTree{
    vll tree;
    ll n;
    SegTree(ll n): n(n), tree(2*n+1,INF){}

    ll MIN(ll a, ll b){
        a += n; b += n;
        ll sm = INF;
        while(a <= b){
            if(a%2 == 1) sm = min(sm,tree[a++]);
            if(b%2 == 0) sm = min(sm,tree[b--]);
            a >>= 1; b >>= 1;
        }
        return sm;
    }

    void add(ll k, ll x){
        k += n;
        tree[k] = min(tree[k],x);
        for(k /= 2 ; k>=1; k/=2){
            tree[k] = min(tree[2*k],tree[2*k+1]);
        }
    }

};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll n,q;cin>>n>>q;
    SegTree st(n);
    rep(i,0,n){
        ll a;cin>>a;
        st.add(i,a);
    }

    rep(i,0,q){
        ll a,b;cin>>a>>b;
        cout << st.MIN(a-1,b-1) << "\n";
    }

}