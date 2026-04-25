#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    ll n,k;cin>>n>>k;
    ll x,a,b,c;cin>>x>>a>>b>>c;
    deque<ll> s;
    ll ans = 0;
    ll last = x;
    rep(i,0,k){
        while(!s.empty() && s.back()>x)s.pop_back();
        s.push_back(x);
        x=(a*x+b)%c;
    }
    ans ^= s.front();
    rep(i,k,n){
        if(last == s.front())s.pop_front();
        while(!s.empty() && s.back() > x)s.pop_back();
        s.push_back(x);
        x = (a*x+b)%c;
        last = (a*last+b)%c;
        ans^=s.front();
    }
    cout << ans << "\n";
}