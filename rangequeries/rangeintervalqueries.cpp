#include "bits/stdc++.h"
using namespace std;
typedef int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct SegTree{
    ll n;
    vector<vll> tree;

    vll merge(const vll& a, const vll& b){
        vll ret;
        ret.reserve(a.size()+b.size());
        ll i = 0, j = 0;
        while(i<a.size() && j<b.size()){
            if(a[i]<=b[j]){
                ret.push_back(a[i]);
                i++;
            }
            else{
                ret.push_back(b[j]);
                j++;
            }
        }
        while(i<a.size()){
            ret.push_back(a[i++]);
        }
        while(j<b.size()){
            ret.push_back(b[j++]);
        }
        return ret;
    }

    SegTree(ll sz, vll& a){
        n = 1;
        while(n<sz)n<<=1;
        tree.assign(2*n,vll{});

        rep(i,n,n+sz){
            tree[i] = {a[i-n]};
        }
        for(ll i = n-1 ; i>=1 ; --i){
            tree[i] = merge(tree[2*i], tree[2*i+1]);
        }
    }

    ll query(ll a, ll b, ll c, ll d){
        a += n-1;
        b += n-1;
        ll ans = 0;
        while(a <= b){
            if(a&1){
                auto &v = tree[a];
                ans += upper_bound(v.begin(),v.end(),d)-lower_bound(v.begin(),v.end(),c);
                a++;
            }
            if(!(b&1)){
                auto &v = tree[b];
                ans += upper_bound(v.begin(),v.end(),d)-lower_bound(v.begin(),v.end(),c);
                b--;
            }
            a >>= 1;
            b >>= 1;
        }
        return ans;
    }
};


int main(){
    cin.tie(0)->sync_with_stdio(0);
   
    ll n,q;cin>>n>>q;
    vll a(n);
    for(auto& i : a)cin>>i;
    SegTree st(n, a);

    rep(i,0,q){
        ll A,B,C,D;cin>>A>>B>>C>>D;
        cout << st.query(A,B,C,D) << "\n";
    }
}