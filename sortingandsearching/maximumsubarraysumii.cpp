#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,a,b;cin>>n>>a>>b;
    vll x(n+1),pref(n+1,0);
    rep(i,1,n+1){cin>>x[i];pref[i]=pref[i-1]+x[i];}

    multiset<ll> s;
    ll ans = -4e18;

    rep(i,1,n+1){
        if(i-a>=0)s.insert(pref[i-a]);

        if(i-b-1>=0){
            auto it = s.find(pref[i-b-1]);
            if(it != s.end())s.erase(it);
        }

        if(!s.empty()){
            ans = max(ans, pref[i]-*s.begin());
        }
    }

    cout<<ans<<"\n";
    return 0;
}