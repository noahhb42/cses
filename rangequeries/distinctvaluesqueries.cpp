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
        while(n < sz)n<<=1;
        tree.assign(2*n,0);
    }

    void insert(ll k, ll x){
        k+=n;
        tree[k] = x;
        for(k/=2 ; k>=1 ; k/=2){
            tree[k] = tree[2*k] + tree[2*k+1];
        }
    }

    ll query(ll l, ll r){
        l+=n;
        r+=n;
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

struct Query{
    ll l, r, id;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n,q;cin>>n>>q;
    vll a(n);
    vector<Query> qs(q);
    map<ll,ll> last;

    rep(i,0,n)cin>>a[i];
    rep(i,0,q){
        cin>>qs[i].l>>qs[i].r;
        qs[i].id = i;
    }

    sort(qs.begin(),qs.end(),[&](const Query& q1, const Query& q2){
        return q1.r<q2.r;
    });

    SegTree st(n);
    vll ans(q);

    ll cur = 0;
    for(auto &i : qs){
        while(cur <= i.r-1){
            if(last.find(a[cur]) != last.end()){
                st.insert(last[a[cur]],0);
            }
            last[a[cur]] = cur;
            st.insert(cur++,1);
        }
        ans[i.id] = st.query(i.l-1,i.r-1);
    }

    for(auto &i : ans)cout<<i<<"\n";
}