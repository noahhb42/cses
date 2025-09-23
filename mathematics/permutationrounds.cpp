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

ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    vll p(n+1);
    rep(i,1,n+1)cin>>p[i];

    vll vis(n+1), lens(0);
    rep(i,1,n+1){
        if(!vis[i]){
            ll cr = i, len = 0;
            while(!vis[cr]){
                vis[cr] = 1;
                len++;
                cr = p[cr];
            }
            lens.push_back(len);
        }
    }

    vll spf(n+1), primes(0);
    rep(i,2,n+1){
        if(!spf[i]){
            spf[i] = i;
            primes.push_back(i);
        }
        for(auto p : primes){
            ll v = p*i;
            if (v>n)break;
            spf[v] = p;
            if (i % p == 0) break;
        }
    }

    vll maxE(n+1, 0);
    for(auto L : lens){
        ll x = L;
        while(x>1){
            ll p = spf[x], cnt = 0;
            while(x>1 && spf[x]==p){
                x/=p;
                cnt++;
            }
            if(cnt > maxE[p])maxE[p]=cnt;
        }
    }

    ll ans = 1;
    for(auto p : primes){
        if(maxE[p]){
            ans = ans * powmod(p,maxE[p]) % mod;
        }
    }
    cout << ans << "\n";
}