#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t;cin>>t;
    vll q(t);
    ll nmax = 0;
    rep(i,0,t){
        cin>>q[i];
        nmax = max(nmax, q[i]);
    }

    const ll INF = 1LL<<18;
    vll X(nmax+1, INF), Y(nmax+1, INF);

    ll M = (ll)sqrtl(nmax);
    for(ll x = 0 ; x <= M ; ++x){
        ll xx = x*x;
        ll ymax = (ll)sqrtl(nmax-x*x);
        for(ll y = x ; y<=ymax ; ++y){
            ll s = xx+y*y;
            if(X[s]==INF){
                X[s] = x;
                Y[s] = y;
            }
        }
    }

    for(ll n : q){
        for(ll s = 0 ; s<=n ; ++s){
            if(X[s] != INF && X[n-s] != INF){
                cout<<X[s]<<" "<<Y[s]<<" "<<X[n-s]<<" "<<Y[n-s]<<"\n";
                break;
            }
        }
    }

}