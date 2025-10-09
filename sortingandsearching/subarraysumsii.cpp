#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,x;cin>>n>>x;
    ll ans = 0, pref = 0;
    map<ll,ll> cnt{};
    cnt[0]=1;
    rep(i,0,n){
        ll a;cin>>a;
        pref+=a;
        auto it = cnt.find(pref-x);
        if(it != cnt.end()){
            ans+=it->second;
        }
        cnt[pref]++;
    }
    cout<<ans<<"\n";
}