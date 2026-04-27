#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = (ll)1e18;

struct SegTree{
    ll n;
    vll tree;

    SegTree(ll sz){
        n = 1;
        while(n < sz)n <<= 1;
        tree.assign(2*n,0);
    }

    void insert(ll k, ll x){
        k += n;
        tree[k] = x;
        for(k /= 2 ; k >= 1 ; k /= 2){
            tree[k] = tree[2*k] + tree[2*k+1];
        }
    }

    ll query(ll l, ll r){
        l += n;
        r += n;
        ll s = 0;
        while(l <= r){
            if(l%2 == 1)s+=tree[l++];
            if(r%2 == 0)s+=tree[r--];
            l >>= 1;
            r >>= 1;
        }
        return s;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n,q;cin>>n>>q;
    SegTree st(n);
    vll a(n);
    ll len = 64 - __builtin_clzll(n);
    vvll up(n,vll(len,n)), cost(n,vll(len,INF));

    rep(i,0,n){
        cin>>a[i];
        st.insert(i,a[i]);
    }

    stack<pair<ll,ll>> t;
    t.push({INF,n});

    for(ll i = n-1 ; i>=0 ; --i){
        ll val = a[i];
        while(val >= t.top().first)t.pop();

        up[i][0] = t.top().second;
        cost[i][0] = (up[i][0]-i)*val - st.query(i,up[i][0]-1);

        t.push(make_pair(val,i));
    }

    for(ll e = 1 ; e<len ; ++e){
        rep(i,0,n){
            if(up[i][e-1] != n){
                up[i][e] = up[up[i][e-1]][e-1];
                cost[i][e] = cost[i][e-1] + cost[up[i][e-1]][e-1];
            }
        }
    }

    rep(i,0,q){
        ll l,r;cin>>l>>r;
        l--;r--;
        ll c = 0;
        for(ll e = len-1 ; e>=0 ; --e){
            if(up[l][e] <= r){
                c += cost[l][e];
                l = up[l][e];
            }
        }
        if(l < r){
            c += (r-l+1)*a[l] - st.query(l,r);
        }
        cout << c << "\n";
    }
}