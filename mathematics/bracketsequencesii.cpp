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
    ll n;cin>>n;
    string s;cin>>s;
    ll k = (ll)s.size();

    if(n%2==1){cout<<"0\n";return 0;}
    ll T = n/2;

    ll open = 0, closed = 0, bal = 0, minbal = 0;
    for(auto c : s){
        if(c=='('){
            open++;
            bal++;
        }
        else{
            closed++;
            bal--;
        }
        minbal=min(minbal,bal);
    }

    if(minbal < 0 || open > T || closed > T){
        cout<<"0\n";
        return 0;
    }

    ll m = n-k;
    ll u = T-open;
    ll d = T-closed;

    vll fact(n+1), invfact(n+1);
    fact[0] = 1;
    rep(i,1,n+1){
        fact[i] = fact[i-1] * i % mod;
    }
    invfact[n] = powmod(fact[n],mod-2);
    for(ll i = n-1 ; i>=0 ; --i){
        invfact[i] = invfact[i+1] * (i+1) % mod;
    }

    auto nCr = [&](ll a, ll b) -> ll{
        if(b > a || b < 0)return 0;
        return fact[a] * invfact[b] % mod * invfact[a-b] % mod;
    };

    ll ans = ((nCr(m,d) - nCr(m,d+1)) % mod + mod) % mod;
    cout << ans << "\n";
}