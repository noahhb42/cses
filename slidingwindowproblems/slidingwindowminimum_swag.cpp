#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)
 
const ll INF = (ll)1e10;

struct SWAG{
    vector<pair<ll,ll>> s1, s2;

    void push(ll x){
        ll cur = x;
        if(!s1.empty())cur = min(cur,s1.back().second);
        s1.push_back({x,cur});
    }

    void move(){
        while(!s1.empty()){
            ll x = s1.back().first;
            s1.pop_back();
            ll cur = x;
            if(!s2.empty())cur=min(cur,s2.back().second);
            s2.push_back({x,cur});
        }
    }

    void pop(){
        if(s2.empty())move();
        s2.pop_back();
    }

    ll get_min(){
        ll mn = INF;
        if(!s1.empty())mn=min(mn,s1.back().second);
        if(!s2.empty())mn=min(mn,s2.back().second);
        return mn;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    ll n,k;cin>>n>>k;
    ll x,a,b,c;cin>>x>>a>>b>>c;

    SWAG sw;

    rep(i,0,k){
        sw.push(x);
        x=(x*a+b)%c;
    }

    ll ans = sw.get_min();

    rep(i,k,n){
        sw.pop();
        sw.push(x);
        ans ^= sw.get_min();
        x=(x*a+b)%c;
    }

    cout << ans << '\n';
}