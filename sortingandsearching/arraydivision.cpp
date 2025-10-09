#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,k;cin>>n>>k;
    vll x(n);
    rep(i,0,n)cin>>x[i];

    ll a=0,b=0;
    rep(i,0,n){
        a=max(a,x[i]);
        b+=x[i];
    }
    a--;

    auto cnt = [&](vll& x, ll val) -> ll{
        ll cnt = 1;
        ll cr = 0;
        for(auto i : x){
            if(cr+i>val){
                cnt++;
                cr = i;
                continue;
            }
            cr+=i;
        }
        return cnt;
    };

    while(b-a>1){
        ll m = (a+b)/2;
        ll c = cnt(x, m);
        if(c>k)a=m;
        else b=m;
    }
    cout<<b<<"\n";
    return 0;
}