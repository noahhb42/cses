#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct SWAG{
    vector<pair<ll,ll>> s1, s2;
    
    void push(ll x){
        ll cur = x;
        if(!s1.empty())cur |= s1.back().second;
        s1.push_back({x,cur});
    }

    void move(){
        while(!s1.empty()){
            ll x = s1.back().first;
            s1.pop_back();
            ll cur = x;
            if(!s2.empty())cur|=s2.back().second;
            s2.push_back({x,cur});
        }
    }

    void pop(){
        if(s2.empty())move();
        s2.pop_back();
    }

    ll get_or(){
        ll ans = 0;
        if(!s1.empty())ans|=s1.back().second;
        if(!s2.empty())ans|=s2.back().second;
        return ans;
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

    ll ans = sw.get_or();

    rep(i,k,n){
        sw.pop();
        sw.push(x);
        ans^=sw.get_or();
        x=(x*a+b)%c;
    }

    cout << ans << '\n';
}