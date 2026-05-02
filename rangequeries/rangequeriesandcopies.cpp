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
        if(lo + 1 < hi){
            ll mid = lo + (hi-lo)/2;
            l = new Node(v,lo,mid), r = new Node(v,mid,hi);
            pull();
        }
        else val = v[lo];
    }

    Node(const Node& o) = default;

    void pull(){
        val = 0;
        if(l) val += l->val;
        if(r) val += r->val;
    }

    ll query(ll L, ll R){
        if(R <= lo || hi <= L)return 0;
        if(L <= lo && hi <= R)return val;
        return l->query(L,R)+r->query(L,R);
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
    vector<Node*> persistent;
    vll v(n);
    rep(i,0,n)cin>>v[i];

    persistent.push_back(new Node(v,0,n));

    rep(_,0,q){
        ll op;cin>>op;
        if(op == 1){
            ll a,b,c;cin>>a>>b>>c;
            a--;b--;
            persistent[a] = persistent[a]->update(b,c);
        }
        else if(op == 2){
            ll a,b,c;cin>>a>>b>>c;
            a--;b--;
            cout << persistent[a]->query(b,c) << "\n";
        }
        else{
            ll k;cin>>k;k--;
            persistent.push_back(persistent[k]);
        }
    }
}