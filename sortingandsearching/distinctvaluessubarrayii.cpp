#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,k;cin>>n>>k;
    vll a(n);
    rep(i,0,n)cin>>a[i];

    map<ll,ll> cnt;

    ll ans = 0;
    ll l=0, distinct = 0;
    rep(r,0,n){
        if(cnt[a[r]]++==0)++distinct;
        while(distinct>k){
            if(--cnt[a[l]]==0)--distinct;
            ++l;
        }
        ans+=r-l+1;
    }
    cout<<ans<<"\n";
}