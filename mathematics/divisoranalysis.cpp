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
ll inv(ll a){return powmod((a%mod+mod)%mod,mod-2);}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    vll p(n),k(n);
    rep(i,0,n)cin>>p[i]>>k[i];

    ll num_div = 1;
    rep(i,0,n){
        num_div = (ll) (((__int128)num_div * ((k[i]+1)%mod)) % mod);
    }

    ll sum_div = 1;
    rep(i,0,n){
        ll a = p[i] % mod;
        ll num = (powmod(a, k[i]+1) - 1 + mod) % mod;
        ll den = (a - 1 + mod) % mod;
        sum_div = (ll)(((__int128)sum_div * ((__int128)num * inv(den) % mod)) % mod);
    }

    bool all_even = true;
    for(ll e : k){
        if(e&1)all_even = false;
    }

    ll smdiv = 1;
    rep(i,0,n){
        smdiv = (ll)(((__int128)smdiv * ((k[i]+1)%phi))%phi);
    }

    ll prod_div = 1;
    if(!all_even){
        ll dhalf = 1;
        bool halved = false;
        rep(i,0,n){
            ll term = (k[i]+1) % phi;
            if(!halved && k[i]&1){
                ll t = (k[i]+1)/2;
                term = t % phi;
                halved = true;
            }
            dhalf = (ll)(((__int128)dhalf * term % phi) % phi);
        }
        rep(i,0,n){
            ll exp = ((__int128)(k[i]%phi) * dhalf) % phi;
            prod_div = ((__int128)prod_div * powmod(p[i],exp)) % mod;
        }
    }
    else{
        rep(i,0,n){
            ll halfk = (k[i]/2) % phi;
            ll exp = ((__int128)halfk * smdiv) % phi;
            prod_div = ((__int128)prod_div * powmod(p[i],exp)) % mod;
        }
    }

    cout<<num_div<<" "<<sum_div<<" "<<prod_div<<"\n";
}