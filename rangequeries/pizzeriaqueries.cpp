#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = (ll)1e18;

struct SegTree{
    ll n;
    vector<pair<ll,ll>> tree;
    
    SegTree(ll sz): n(sz), tree(2*sz,{INF,INF}){}

    void insert(ll k, ll x){
        k += n;
        tree[k] = make_pair(x-k+n, x+k-n);
        for(k /= 2 ; k >= 1 ; k /= 2){
            auto l = tree[2*k], r = tree[2*k+1];
            tree[k] = make_pair(min(l.first, r.first), min(l.second, r.second));
        }
    }

    pair<ll,ll> query(ll a, ll b){
        pair<ll,ll> mn = make_pair(INF, INF);
        a += n;
        b += n;
        while(a <= b){
            if(a%2 == 1){
                mn.first = min(mn.first, tree[a].first);
                mn.second = min(mn.second, tree[a].second);
                a++;
            }
            if(b%2 == 0){
                mn.first = min(mn.first, tree[b].first);
                mn.second = min(mn.second, tree[b].second);
                b--;
            }
            a >>= 1;
            b >>= 1;
        }
        return mn;
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
        ll op;cin>>op;
        if(op == 1){
            ll a,b;cin>>a>>b;
            st.insert(a-1,b);
        }
        else{
            ll a;cin>>a;
            cout << min(a-1 + st.query(0,a-1).first, -a+1 + st.query(a-1,n-1).second) << "\n";
        }
    }
}