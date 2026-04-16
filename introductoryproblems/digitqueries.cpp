#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

void solve(){
    ll n;cin>>n;
    ll i = 1;
    while(n - 9*(ll)pow(10,i-1)*i > 0){
        n-=9*(ll)pow(10,i-1)*i;
        i++;
    }
    ll nr = (ll)pow(10,i-1)-1+(n+i-1)/i;
    vll a;
    while(nr){
        a.push_back(nr%10);
        nr/=10;
    }
    reverse(a.begin(),a.end());
    cout << a[(n-1)%i] << "\n";
}

int main(){
    ll t;cin>>t;
    while(t--)solve();
}