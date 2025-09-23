#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mod = 1e9+7;

ll powmod(ll a, ll b){
    ll r = 1;
    while(b){
        if(b & 1) r = (r*a)%mod;
        b>>=1;
        a = (a*a)%mod;
    }
    return r;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;cin>>s;
    map<char,ll> m{};
    set<char> a;
    for(char c : s){
        m[c]++;
        a.insert(c);
    }

    ll n = (ll)s.size();

    vll fact(n+1), invfact(n+1);

    fact[0]=1;
    for(ll i = 1 ; i<=n ; ++i){
        fact[i] = fact[i-1] * i % mod;
    }
    invfact[n] = powmod(fact[n],mod-2);
    for(ll i = n-1 ; i>=0 ; i--){
        invfact[i] = invfact[i+1] * (i+1) % mod;
    }

    ll ans = fact[n];
    for(auto c : a){
        ans = ans * invfact[m[c]] % mod;
    }

    cout << ans << "\n";

}