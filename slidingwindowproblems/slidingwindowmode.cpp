#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    ll n,k;cin>>n>>k;
    vector<ll> a(n);
    for(auto &i : a)cin>>i;

    set<pair<ll,ll>> s;
    map<ll,ll> freq;

    rep(i,0,k){
        if(freq[a[i]]++ == 0){
            s.insert({1,-a[i]});
        }
        else{
            s.erase(s.find({freq[a[i]]-1,-a[i]}));
            s.insert({freq[a[i]],-a[i]});
        }
    }

    cout << -(*s.rbegin()).second << " ";

    rep(i,k,n){
        if(freq[a[i]]++ == 0){
            s.insert({1,-a[i]});
        }
        else{
            s.erase(s.find({freq[a[i]]-1,-a[i]}));
            s.insert({freq[a[i]],-a[i]});
        }

        if(--freq[a[i-k]]==0){
            s.erase(s.find({1,-a[i-k]}));
        }
        else{
            s.erase(s.find({freq[a[i-k]]+1,-a[i-k]}));
            s.insert({freq[a[i-k]],-a[i-k]});
        }

        cout << -(*s.rbegin()).second << " ";
    }

    cout << "\n";
}