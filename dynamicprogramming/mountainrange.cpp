#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll inf = (ll)1e18;

struct Node{
    Node *l = 0, *r = 0;
    ll lo, hi, madd = 0, mset = inf, val = 0;
    Node(vll& v, ll lo, ll hi): lo(lo), hi(hi){
        if(lo + 1 < hi){
            ll mid = lo + (hi-lo)/2;
            l = new Node(v, lo, mid), r = new Node(v, mid, hi);
            val = max(l->val, r->val);
        }
        else{
            val = v[lo];
        }
    }
    void set(ll L, ll R, ll x){
        if(R <= lo || hi <= L)return;
        if(L <= lo && hi <= R)madd = 0, val = mset = x;
        else{
            push(), l->set(L,R,x), r->set(L,R,x);
            val = max(l->val, r->val);
        }
    }
    void add(ll L, ll R, ll x){
        if(R <= lo || hi <= L)return;
        if(L <= lo && hi <= R){
            if(mset != inf)mset += x;
            else madd += x;
            val += x;
        }
        else{
            push(), l->add(L,R,x), r->add(L,R,x);
            val = max(l->val, r->val);
        }
    }
    ll query(ll L, ll R){
        if(R <= lo || hi <= L)return 0;
        if(L <= lo && hi <= R)return val;
        else{
            push();
            return max(l->query(L,R), r->query(L,R));
        }
    }
    void push(){
        if(lo + 1 == hi)return;
        if(mset != inf){
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        }
        else if(madd){
            l->add(lo,hi,madd), r->set(lo,hi,madd), madd = 0;
        }
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll n;cin>>n;
    vll v(n), V(n,0);
    rep(i,0,n)cin>>v[i];
    vll L(n,-1), R(n,n);
    
    stack<pair<ll,ll>> s;
    rep(i,0,n){
        while(!s.empty() && v[i] > s.top().first){
            s.pop();
        }
        if(!s.empty()){
            L[i] = s.top().second;
        }
        s.push({v[i], i});
    }

    stack<pair<ll,ll>> t;
    for(ll i = n-1 ; i>=0 ; --i){
        while(!t.empty() && v[i] > t.top().first){
            t.pop();
        }
        if(!t.empty()){
            R[i] = t.top().second;
        }
        t.push({v[i],i});
    }

    vector<pair<ll,ll>> order;
    rep(i,0,n){
        order.push_back({v[i],i});
    }
    sort(order.begin(),order.end());

    Node dp(V,0,n);
    rep(i,0,n){
        auto [val, id] = order[i];
        ll dpval = dp.query(L[id]+1,R[id]);
        dp.set(id,id+1,dpval+1);
    }
    cout << dp.query(0,n) << "\n";
}