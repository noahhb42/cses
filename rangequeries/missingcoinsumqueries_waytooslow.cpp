#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)
 
struct Node{
    Node *l = 0, *r = 0;
    ll lo, hi, val = 0;
    
    Node(vll& v, ll lo, ll hi): lo(lo), hi(hi){
        if(lo+1 < hi){
            ll mid = lo + (hi-lo)/2;
            l = new Node(v,lo,mid), r = new Node(v,mid,hi);
            pull();
        }
        else val = v[lo];
    }
 
    Node(const Node& o) = default;
 
    void pull(){
        val = 0;
        if(l)val+=l->val;
        if(r)val+=r->val;
    }
 
    ll query(ll L, ll R){
        if(R <= lo || hi <= L)return 0;
        if(L <= lo && hi <= R)return val;
        return l->query(L,R) + r->query(L,R);
    }
 
    Node* update(ll pos, ll x){
        Node* res = new Node(*this);
        if(lo + 1 == hi){
            res->val = x;
            return res;
        }
 
        ll mid = lo + (hi-lo)/2;
        if(pos < mid){
            res->l = l->update(pos,x);
        }
        else{
            res->r = r->update(pos,x);
        }
        res->pull();
        return res;
    }
};
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
 
    ll n,q;cin>>n>>q;
    vector<pair<ll,ll>> order;
    rep(i,0,n){
        ll a;cin>>a;
        order.push_back(make_pair(a,i));
    }
    sort(order.begin(),order.end());
 
    vector<Node*> tree(n+1);
    vll tmp(n,0);
 
    tree[0] = new Node(tmp,0,n);
 
    rep(i,0,n){
        tree[i+1] = tree[i]->update(order[i].second, order[i].first);
    }
 
    auto solve = [&](ll L, ll R){
        ll x = 0;
        while(true){
            ll k = upper_bound(order.begin(),order.end(),make_pair(x+1,LLONG_MAX))-order.begin();
 
            ll s = tree[k]->query(L,R);
 
            if(s == x)return x+1;
            x=s;
        }
    };
 
    rep(_,0,q){
        ll l,r;cin>>l>>r;
        cout << solve(l-1,r) << "\n";
    }
}