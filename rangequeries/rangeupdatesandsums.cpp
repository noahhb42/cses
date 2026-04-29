#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = (ll)1e18;

struct Node{
    Node *l = 0, *r = 0;
    ll lo, hi, mset = INF, madd = 0, val = 0;
    Node(ll lo, ll hi): lo(lo), hi(hi){}
    Node(vll& v, ll lo, ll hi): lo(lo), hi(hi){
        if(lo + 1 < hi){
            ll mid = lo + (hi-lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = l->val + r->val;
        }
        else val = v[lo];
    }
    ll query(ll L, ll R){
        if(R <= lo || hi <= L)return 0;
        if(L <= lo && R >= hi)return val;
        push();
        return l->query(L,R) + r->query(L,R);
    }
    void set(ll L, ll R, ll x){
        if(R <= lo || hi <= L)return;
        if(L <= lo && hi <= R)mset = x, val = x*(hi-lo), madd = 0;
        else{
            push(), l->set(L,R,x), r->set(L,R,x);
            val = l->val + r->val;
        }
    }
    void add(ll L, ll R, ll x){
        if(R <= lo || hi <= L)return;
        if(L <= lo && hi <= R){
            if(mset != INF) mset += x;
            else madd += x;
            val += x*(hi-lo);
        }
        else{
            push(), l->add(L,R,x), r->add(L,R,x);
            val = l->val + r->val;
        }
    }
    void push(){
        if(!l){
            ll mid = lo + (hi-lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if(mset != INF){
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = INF;
        }
        else if(madd){
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
        }
    }

};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n,q;cin>>n>>q;
    vll v(n);
    rep(i,0,n)cin>>v[i];

    Node tree(v,0,n);
    
    rep(i,0,q){
        ll op;cin>>op;
        if(op == 1){
            ll a,b,x;cin>>a>>b>>x;
            tree.add(a-1,b,x);
        }
        else if(op == 2){
            ll a,b,x;cin>>a>>b>>x;
            tree.set(a-1,b,x);
        }
        else{
            ll a,b;cin>>a>>b;
            cout << tree.query(a-1,b) << "\n";
        }
    }
}