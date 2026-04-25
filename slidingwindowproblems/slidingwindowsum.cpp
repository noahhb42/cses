#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    ll n,k;cin>>n>>k;
    ll x,a,b,c;cin>>x>>a>>b>>c;
    
    ll sm = 0;
    ll first = x;
    for(ll i = 0 ; i < k ; ++i){
        sm+=x;
        x=(a*x+b)%c;
    }
    ll ans = sm;
    for(ll i = k ; i<n ; ++i){
        sm+=x;
        sm-=first;
        first = (first*a+b)%c;
        x = (x*a+b)%c;
        ans ^= sm;
    }
    cout << ans << '\n';
}