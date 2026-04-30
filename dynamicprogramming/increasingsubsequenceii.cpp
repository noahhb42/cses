#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll inf = (ll)1e18;
const ll mod = (ll)1e9+7;

struct Node{
    Node *l = 0, *r = 0;
    ll lo, hi, madd = 0, mset = inf, val = 0;
    Node(vll& v, ll lo, ll hi): lo(lo), hi(hi){
        if(lo + 1 < hi){
            ll mid = lo + (hi-lo)/2;
            l = new Node(v,lo,mid), r = new Node(v,mid,hi);
            val = (l->val + r->val)%mod;
        }
        else val = v[lo];
    }
    void set(ll L, ll R, ll x){
        if(R <= lo || hi <= L)return;
        if(L <= lo && hi <= R)mset = x, madd = 0, val = ((hi-lo)*x)%mod;
        else{
            push(), l->set(L,R,x), r->set(L,R,x);
            val = (l->val + r->val)%mod;
        }
    }
    void add(ll L, ll R, ll x){
        if(R <= lo || hi <= L)return;
        if(L <= lo && hi <= R){
            if(mset != inf)mset = (mset+x)%mod;
            else madd = (madd + x)%mod;
            val = (val + (hi-lo)*x)%mod;
        }
        else{
            push(), l->add(L,R,x), r->add(L,R,x);
            val = (l->val + r->val)%mod;
        }
    }
    ll query(ll L, ll R){
        if(R <= lo || hi <= L)return 0;
        if(L <= lo && hi <= R)return val;
        else{
            push();
            return (l->query(L,R) + r->query(L,R))%mod;
        }
    }
    void push(){
        if(lo + 1 == hi)return;
        if(mset != inf){
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = 0;
        }
        else if(madd){
            l->add(lo,hi,madd), r->set(lo,hi,madd), madd = 0;
        }
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;cin>>n;
    vll v(n), V(n,0);
    rep(i,0,n)cin>>v[i];

    vector<pair<ll,ll>> order;
    rep(i,0,n)order.push_back({-v[i], i});
    sort(order.begin(),order.end());

    Node st(V,0,n);
    rep(i,0,n){
        ll cur = 1;
        ll ind = order[i].second;
        cur += st.query(ind+1,n);
        st.set(ind,ind+1,cur);
    }
    cout << st.query(0,n) << "\n";
}