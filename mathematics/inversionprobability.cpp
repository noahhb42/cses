#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;

    vll r(n);
    rep(i,0,n)cin>>r[i];

    auto prob = [&](ll a, ll b){
        if(a <= b)return (a-1)/(2.0*b);
        else return 1.0-(b+1)/(2.0*a);
    };

    long double ans = 0;

    for(int a = 0 ; a<n ; ++a){
        for(int b = a+1 ; b<n ; ++b){
            ans+=prob(r[a],r[b]);
        }
    }

    cout.precision(6);
    cout<<fixed<<ans<<"\n";
}

/*
ROUNDING ERRORS IN CPP --- USING PYTHON INSTEAD
*/