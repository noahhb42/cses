#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    
    const ll mxn = 1e6+1;
    vll freq(mxn,0);
    ll mx = 0;
    ll x;
    rep(i,0,n){
        cin>>x;
        ++freq[x];
        mx = max(x,mx);
    }

    vll mu(mx+1), lp(mx+1), primes(0);
    mu[1]=1;
    rep(i,2,mx+1){
        if(lp[i]==0){lp[i] = i; primes.push_back(i); mu[i]=-1;}
        for(ll p : primes){
            ll v = p*i;
            if(v>mx)break;
            lp[v]=p;
            if(i%p == 0){mu[v]=0; break;}
            else mu[v]=-mu[i];
        }
    }

    vll mult(mx+1,0);
    rep(d,1,mx+1)for(ll k = d ; k<=mx ; k+=d)mult[d]+=freq[k];

    ll ans = 0;
    rep(d,1,mx+1){
        ll c = mult[d];
        if(c>=2 && mu[d]!=0){
            ans+= mu[d] * (c*(c-1)/2);
        }
    }

    cout<<ans<<"\n";

}