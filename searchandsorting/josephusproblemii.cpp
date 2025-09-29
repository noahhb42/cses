#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

vll ans(0);

ll jos(ll n, ll k){
    if(n==1)return 0;
    return (jos(n-1,k)+k)%n;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;

}
