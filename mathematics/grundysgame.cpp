#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct GrundyGame{
    map<ll,ll> grundynum;

    ll grundy(ll n){
        if(n<=2)return 0;
        if(grundynum.find(n)!=grundynum.end())return grundynum[n];

        set<ll> reached;
        for(ll i = 1 ; i<=n/2 ; ++i){
            if(i+i==n)continue;
            reached.insert(grundy(i) ^ grundy(n-i));
        }

        ll g = 0;
        while(reached.count(g))g++;
        grundynum[n] = g;
        return g;
    }

};


int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll bound = 3000;

    GrundyGame g{};

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        if(n<=bound)cout<<(g.grundy(n) ? "first\n" : "second\n");
        else cout<<"first\n";
    }
}