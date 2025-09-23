#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

ll powmod(ll a, ll b, ll mod){
    __int128 res = 1;
    __int128 A = a;
    __int128 B = b;
    A%=mod;
    while(B){
        if(B&1)res = res * A % mod;
        A = A*A % mod;
        B>>=1;
    }
    return (ll)res;
}

bool is_prime_probably(ll n){
    rep(_,0,15){
        ll base = rand()%n;
        while(base == 0)base = rand()%n;
        if(powmod(base,n-1,n)!=1)return false;
    }
    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t;cin>>t;
    rep(i,0,t){
        ll n;cin>>n;
        if(n==1){
            cout<<"2\n";
            continue;
        }
        if(n&1)n++;
        for(ll p = n+1 ; ; p+=2){
            if(is_prime_probably(p)){
                cout<<p<<"\n";
                break;
            }
        }
    }
}