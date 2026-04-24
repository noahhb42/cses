#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct Fenwick{
    ll n;
    vll a;
    Fenwick(ll n): n(n), a(n+1,0){}
    void add(ll v, ll k){
        while(k<=n){
            a[k]^=v;
            k += k&-k;
        }
    }
    ll sum(ll s, ll e){
        ll sm = 0;
        ll cur = e;
        while(cur >= 1){
            sm ^= a[cur];
            cur -= cur&-cur;
        }
        cur = s-1;
        while(cur >= 1){
            sm ^= a[cur];
            cur -= cur&-cur;
        }
        return sm;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll n,q;cin>>n>>q;
    Fenwick f(n);
    rep(i,1,n+1){
        ll a;cin>>a;
        f.add(a,i);
    }
    rep(i,0,q){
        ll a,b;cin>>a>>b;
        cout << f.sum(a,b) << "\n";
    }

}