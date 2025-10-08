#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    vll a(n);
    rep(i,0,n)cin>>a[i];

    map<ll,ll> m{};
    ll ans = 0;
    ll l = 0;
    rep(r,0,n){
        m[a[r]]++;
        while(m[a[r]]>1){
            m[a[l]]--;
            l++;
        }
        ans+=r-l+1;
    }
    cout<<ans<<"\n";
    return 0;
}