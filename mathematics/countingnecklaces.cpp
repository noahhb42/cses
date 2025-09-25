#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mod = 1e9+7;
const ll phi = mod-1;

ll powmod(ll a, ll b){
    ll r = 1;
    while(b){
        if(b & 1) r = (r*a)%mod;
        b>>=1;
        a = (a*a)%mod;
    }
    return r;
}
ll inv(ll a){return powmod(a, mod-2);}

ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b, a%b);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    ll sm = 0;
    rep(i,0,n){
        sm = (sm + powmod(m,gcd(n,i))) % mod;
    }
    sm = (sm * inv(n)) % mod;
    cout << sm << "\n";
}