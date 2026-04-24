#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = (ll)4e18;

struct SegTree{
    ll n;
    vll tree;
    SegTree(ll n): n(n), tree(2*n+1,0){}

    ll sum(ll a, ll b){
        a += n; b += n;
        ll sm = 0;
        while(a <= b){
            if(a%2 == 1) sm += tree[a++];
            if(b%2 == 0) sm += tree[b--];
            a >>= 1; b >>= 1;
        }
        return sm;
    }

    void add(ll k, ll x){
        k += n;
        tree[k] += x;
        for(k /= 2 ; k>=1; k/=2){
            tree[k] = tree[2*k] + tree[2*k+1];
        }
    }

};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll n,q;cin>>n>>q;
    SegTree st(n+1);
    ll last = 0;
    vll cur(n+1,0);
    rep(i,0,n){
        ll a;cin>>a;
        st.add(i,a-last);
        cur[i] = a-last;
        last = a;
    }

    rep(i,0,q){
        ll op;cin>>op;
        if(op == 1){
            ll a,b,u;cin>>a>>b>>u;
            st.add(a-1,u);
            st.add(b,-u);
            cur[a-1] += u;
            cur[b] -= u;
        }
        else{
            ll a;cin>>a;
            cout << st.sum(0,a-1) << "\n";
        }
    }

}