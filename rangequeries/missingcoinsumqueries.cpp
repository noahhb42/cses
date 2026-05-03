#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct Node{
    ll l = 0, r = 0;
    ll sum = 0;
};

vector<Node> st;

ll clone_node(ll v){
    st.push_back(st[v]);
    return (ll)st.size()-1;
}

ll update(ll v, ll lo, ll hi, ll pos, ll add){
    ll u = clone_node(v);
    st[u].sum+=add;

    if(lo+1==hi)return u;

    ll mid = lo + (hi-lo)/2;

    if(pos < mid){
        st[u].l=update(st[v].l,lo,mid,pos,add);
    }
    else{
        st[u].r=update(st[v].r,mid,hi,pos,add);
    }
    return u;
}

ll query(ll v, ll lo, ll hi, ll L, ll R){
    if(v==0 || R <= lo || hi <= L)return 0;
    if(L <= lo && hi <= R)return st[v].sum;
    ll mid = lo + (hi-lo)/2;
    return query(st[v].l, lo, mid, L, R) + query(st[v].r, mid, hi, L, R);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n,q;cin>>n>>q;
    vector<pair<ll,ll>> order(n);
    rep(i,0,n){
        ll a;cin>>a;
        order[i] = make_pair(a,i);
    }
    sort(order.begin(),order.end());

    vll vals(n);
    rep(i,0,n)vals[i] = order[i].first;

    st.reserve((n+5)*20);
    st.push_back(Node());

    vll roots(n+1);
    roots[0] = 0;

    rep(i,0,n){
        roots[i+1] = update(roots[i], 0, n, order[i].second, order[i].first);
    }

    auto solve = [&](ll L, ll R) -> ll{
        ll x = 0;
        while(true){
            ll k = upper_bound(vals.begin(),vals.end(),x+1)-vals.begin();
            ll s = query(roots[k], 0, n, L , R);
            if(s==x)return x+1;
            x=s;
        }
    };

    while(q--){
        ll l,r;cin>>l>>r;
        cout << solve(l-1,r) << "\n";
    }
}