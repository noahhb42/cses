#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = (ll)1e18;

struct SegTree{
    ll n;
    vector<pair<ll,vll>> tree;

    SegTree(ll sz, vll a){
        n = 1;
        while(n < sz)n<<=1;
        tree.assign(2*n,make_pair(-INF,vll{}));

        rep(i,n,n+sz){
            vll temp = {a[i-n]};
            tree[i] = make_pair(a[i-n],temp);
        }
        for(ll i = n-1 ; i >= 1 ; --i){
            auto [ml, vl] = tree[2*i];
            auto [mr, vr] = tree[2*i+1];
            if(vl.empty()){
                tree[i] = tree[2*i+1];
            }
            else if(vr.empty()){
                tree[i] = tree[2*i];
            }
            else{
                vll temp = vl;
                auto it = upper_bound(vr.begin(),vr.end(),ml);
                temp.insert(temp.end(),it,vr.end());
                tree[i] = make_pair(max(ml,mr),temp);
            }
        }
    }

    ll query(ll a, ll b){
        vll L,R;
        a += n;
        b += n;

        while(a <= b){
            if(a%2==1)L.push_back(a++);
            if(b%2==0)R.push_back(b--);
            a >>= 1;
            b >>= 1;
        }
        reverse(R.begin(),R.end());

        ll cur = -INF;
        ll ans = 0;

        auto consume = [&](ll node){
            auto &v = tree[node].second;
            auto it = upper_bound(v.begin(),v.end(),cur);
            ans += v.end() - it;
            cur = max(cur, tree[node].first);
        };

        for(auto node : L)consume(node);
        for(auto node : R)consume(node);

        return ans;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll n,q;cin>>n>>q;
    vll a(n);
    for(auto &i : a)cin>>i;
    SegTree st(n,a);

    rep(i,0,q){
        ll l,r;cin>>l>>r;
        cout << st.query(l-1,r-1) << "\n";
    }
}