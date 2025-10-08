#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    map<ll,ll> m{};
    ll sm = 0;
    rep(i,0,n){
        ll a;cin>>a;
        m[a]++;
        sm+=a;
    }
    ll smaller = 0, bigger = sm;
    ll smallernr = 0, biggernr = n;
    ll mn = 4e18;
    for(auto [key, nr] : m){
        bigger-=nr*key;
        biggernr-=nr;

        ll move = 0;
        move+=bigger-biggernr*key;
        move+=smallernr*key-smaller;
        mn = min(mn,move);

        smaller+=nr*key;
        smallernr+=nr;
    }
    cout<<mn<<"\n";
}