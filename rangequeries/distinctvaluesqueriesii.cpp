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
        tree.assign(2*n,INF);
    }

    void insert(ll k, ll x){
        k += n;
        tree[k] = x;
        for(k /= 2 ; k >= 1 ; k /= 2){
            tree[k] = min(tree[2*k], tree[2*k+1]);
        }
    }

    ll query(ll l, ll r){
        l += n;r += n;
        ll mn = INF;
        while(l <= r){
            if(l%2 == 1)mn=min(mn,tree[l++]);
            if(r%2 == 0)mn=min(mn,tree[r--]);
            l >>= 1;
            r >>= 1;
        }
        return mn;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n,q;cin>>n>>q;
    vll a(n), next(n,INF);
    map<ll,set<ll>> pos;
    SegTree st(n);

    rep(i,0,n){
        cin>>a[i];
        pos[a[i]].insert(i);
    }

    rep(i,0,n){
        if(i >= *pos[a[i]].rbegin())next[i] = INF;
        else next[i] = *pos[a[i]].upper_bound(i);
        st.insert(i,next[i]);
    }

    rep(_,0,q){
        ll op;cin>>op;
        if(op == 1){
            ll k,x;cin>>k>>x;
            k--;

            if(a[k] == x)continue;

            ll val = a[k];
            auto &s1 = pos[val];
            auto it = s1.find(k);

            //delete
            if(it == s1.begin()){
                s1.erase(it);
            }

            else if(it == --s1.end()){
                auto it2 = it;
                it2--;
                next[*it2]=INF;
                st.insert(*it2,INF);
                s1.erase(it);
            }

            else{
                auto it2 = it, it3 = it;
                it2--;
                it3++;
                next[*it2]=*it3;
                st.insert(*it2,*it3);
                s1.erase(it);
            }

            //insert
            auto &s2 = pos[x];
            if(s2.empty()){
                next[k] = INF;
                st.insert(k,INF);
            }
            else if(k < *s2.begin()){
                next[k] = *s2.begin();
                st.insert(k,*s2.begin());
            }
            else if(k > *(--s2.end())){
                next[k] = INF;
                st.insert(k,INF);
                auto it2 = (--s2.end());
                next[*it2] = k;
                st.insert(*it2,k);
            }
            else{
                auto it1 = s2.upper_bound(k);
                auto it2 = it1;
                it2--;
                next[*it2] = k;
                next[k] = *it1;
                st.insert(*it2,k);
                st.insert(k,*it1);
            }
            s2.insert(k);

            a[k] = x;
        }
        else{
            ll l,r;cin>>l>>r;
            l--;r--;
            cout<<(st.query(l,r)>r ? "YES\n" : "NO\n");
        }
    }
}