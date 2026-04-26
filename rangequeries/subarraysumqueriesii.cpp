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
        while(n < sz)n <<= 1;
        tree.assign(2*n,{-INF,-INF,-INF,-INF});
    }

    void insert(ll k, ll x){
        k += n;
        tree[k] = {x,x,x,x};
        for(k /= 2 ; k >= 1 ; k /= 2){
            auto &l = tree[2*k];
            auto &r = tree[2*k+1];
            tree[k] = {
                l[0] + r[0],
                max(l[1], l[0] + r[1]),
                max(l[3]+r[1], max(l[2], r[2])),
                max(l[3]+r[0], r[3])
            };
        }
    }

    ll query(ll a, ll b){
        a += n;
        b += n;
        array<ll,4> l = {-INF, -INF, -INF, -INF}, r = {-INF, -INF, -INF, -INF};
        while(a <= b){
            if(a%2 == 1){
                auto &c = tree[a];
                l = {
                    l[0] + c[0],
                    max(l[1], l[0] + c[1]),
                    max(l[3] + c[1], max(l[2], c[2])),
                    max(l[3] + c[0], c[3])
                };
                a++;
            }
            if(b%2 == 0){
                auto &c = tree[b];
                r = {
                    r[0] + c[0],
                    max(c[1], c[0] + r[1]),
                    max(c[3] + r[1], max(c[2], r[2])),
                    max(r[3]+c[0], c[3])
                };
                b--;
            }
            a >>= 1;
            b >>= 1;
        }
        return max(l[3]+r[1], max(l[2], r[2]));
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
        cout << max(0LL,st.query(a-1,b-1)) << "\n";
    }
}