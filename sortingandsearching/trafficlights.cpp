#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll x,n;cin>>x>>n;
    set<ll> s;
    multiset<ll> gaps;
    s.insert(0);s.insert(x);
    gaps.insert(x);
    rep(i,0,n){
        ll p;cin>>p;
        auto itr = s.lower_bound(p);
        ll p1 = *(itr);
        ll p2 = *prev(itr);

        auto itrr = gaps.find(p1-p2);
        gaps.erase(itrr);

        gaps.insert(p1-p);
        gaps.insert(p-p2);
        s.insert(p);

        cout<<*gaps.rbegin()<<" ";
    }
    cout<<"\n";
    return 0;
}