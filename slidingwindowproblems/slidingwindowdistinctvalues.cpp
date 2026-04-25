#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    ll n,k;cin>>n>>k;
    ll distinct = 0;
    vll a(n);
    for(auto &i : a)cin>>i;
    map<ll,ll> freq;

    rep(i,0,k){
        if(freq[a[i]]++ == 0)distinct++;
    }

    cout << distinct << " ";
    rep(i,k,n){
        if(freq[a[i]]++ == 0)distinct++;
        if(--freq[a[i-k]] == 0)distinct--;

        cout << distinct << " ";
    }
    cout << '\n';
}