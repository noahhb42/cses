#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

ll k1(ll n, ll k);

ll k2(ll n, ll k){
    if(n==1)return 1;
    ll m = n/2;
    if(k<=m)return 2*k;
    if((n&1) == 0){
        return 2*k2(m,k-m)-1;
    }
    else{
        return 2*k1(m+1,k-m)-1;
    }
}

ll k1(ll n, ll k){
    if(n==1)return 1;
    ll m = (n+1)/2;
    if(k<=m)return 2*k-1;
    if((n&1)==0){
        return 2*k1(n/2, k-m);
    }
    else{
        return 2*k2(n/2, k-m);
    }
}

ll kth(ll n, ll k){
    if(k<=n/2)return 2*k;
    return 2 * kth((n+1)/2,k-n/2)-1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll q;cin>>q;
    rep(_,0,q){
        ll n,k;
        cin>>n>>k;
        cout<<k2(n,k)<<"\n";
    }
}