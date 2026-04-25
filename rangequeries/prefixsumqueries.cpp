#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct SegTree{
    ll n;
    vector<pair<ll,ll>> tree;
    
    SegTree(ll sz): n(sz), tree(2*sz,{0,0}){}

    void insert(ll k, ll x){
        k += n;
        tree[k] = {x,x};
        for(k/=2 ; k>=1 ; k/=2){
            auto l = tree[2*k];
            auto r = tree[2*k+1];
            tree[k] = make_pair(l.first + r.first, max(l.second, l.first + r.second));
        }
    }

    pair<ll,ll> query(ll a, ll b){
        a += n;
        b += n;

        pair<ll,ll> left = {0,-(ll)1e18};
        pair<ll,ll> right = {0,-(ll)1e18};

        while(a <= b){
            if(a%2 == 1){
                left = make_pair(left.first + tree[a].first, max(left.second, left.first + tree[a].second));
                a++;
            }
            if(b%2 == 0){
                right = make_pair(tree[b].first + right.first, max(tree[b].second, tree[b].first + right.second));
                b--;
            }
            a >>= 1;
            b >>= 1;
        }

        return make_pair(left.first + right.first, max(left.second, left.first + right.second));
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
        ll op,a,b;cin>>op>>a>>b;
        if(op == 1){
            st.insert(a-1,b);
        }
        else{
            cout << max(0LL, st.query(a-1,b-1).second) << "\n";
        }
    }
}