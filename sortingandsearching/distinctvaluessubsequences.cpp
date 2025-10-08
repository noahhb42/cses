#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    map<ll,ll> m{};
    ll ans = 1;
    rep(i,0,n){
        ll a;cin>>a;
        m[a]++;
    }
    for(auto[x,y] : m){
        ans*=y+1;
        ans%=MOD;
    }
    ans--;
    if(ans<0)ans+=MOD;
    cout<<ans<<"\n";
}