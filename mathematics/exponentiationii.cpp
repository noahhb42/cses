#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll p = 1e9+7;

ll powmod(ll a, ll b, ll mod){
    ll res = 1;
    while(b){
        if(b&1){res*=a;res%=mod;}
        a*=a;
        a%=mod;
        b>>=1;
    }
    return res;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    rep(i,0,n){
        ll a,b,c;cin>>a>>b>>c;
        ll res = powmod(b,c,p-1);
        ll ans = powmod(a,res,p) % p;
        cout<<ans<<endl;
    }
}