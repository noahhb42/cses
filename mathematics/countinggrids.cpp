#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mod = 1e9+7;
const ll phi = mod-1;

ll powmod(ll a, ll b){
    ll r = 1;
    a %= mod;
    b %= phi;
    while(b){
        if(b & 1) r = ( (__int128)r * a ) % mod;
        b>>=1;
        a = ( (__int128)a * a ) % mod;
    }
    return r;
}
ll inv(ll a){return powmod(a, mod-2);}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    auto pw = [&](ll e){return powmod(2,e);};
    ll n2 = ( (__int128)n * n );
    ll A = pw(n2);
    ll B = pw((n2+1)/2);
    ll C = pw((n2+3)/4);
    ll sum = (A + B + 2*C) % mod;
    sum = ( (__int128)sum * inv(4) ) % mod;
    cout << sum << "\n";
}
