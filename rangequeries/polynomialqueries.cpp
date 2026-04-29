#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = (ll)1e18;

struct Node{
    Node *l = 0, *r = 0;
    ll lo, hi, mset = INF, ma = 0, mb = 0, val = 0;
    Node(vll& v, ll lo, ll hi): lo(lo), hi(hi){
        if(lo + 1 < hi){
            ll mid = lo + (hi-lo)/2;
            l = new Node(v,lo,mid), r = new Node(v,mid,hi);
            val = l->val + r->val;
        }
        else val = v[lo];
    }
    ll query(ll L, ll R){
        if(R <= lo || hi <= L)return 0;
        if(L <= lo && hi <= R)return val;
        else{
            push();
            return l->query(L,R) + r->query(L,R);
        }
    }
    void set(ll L, ll R, ll x){
        if(R <= lo || hi <= L)return;
        if(L <= lo && hi <= R)mset = x, ma = 0, mb = 0, val = x*(hi-lo);
        else{
            push(), l->set(L,R,x), r->set(L,R,x);
            val = l->val + r->val;
        }
    }
    void add(ll L, ll R, ll A, ll B){
        if(R <= lo || hi <= L)return;
        if(L <= lo && hi <= R){
            ma += A, mb += B;
            val += A*((hi-1)*hi/2-(lo-1)*lo/2)+(hi-lo)*B;
        }
        else{
            push(), l->add(L,R,A,B), r->add(L,R,A,B);
            val = l->val + r->val;
        }
    }
    void push(){
        if(lo + 1 == hi)return;
        if(mset != INF){
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = INF;
        }
        else if(ma != 0 || mb != 0){
            l->add(lo,hi,ma,mb), r->add(lo,hi,ma,mb), ma = 0, mb = 0;
        }
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n,q;cin>>n>>q;
    vll v(n);
    for(auto&i:v)cin>>i;

    Node st(v,0,n);

    rep(i,0,q){
        ll op;cin>>op;
        if(op == 1){
            ll a,b;cin>>a>>b;
            st.add(a-1,b,1,2-a);
        }
        else{
            ll a,b;cin>>a>>b;
            cout << st.query(a-1,b) << "\n";
        }
    }
}