#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    vll pos(n+1);
    rep(i,0,n){
        ll x;cin>>x;
        pos[x] = i;
    }
    ll rounds = 1;
    rep(i,1,n){
        if(pos[i+1]<pos[i])rounds++;
    }
    cout<<rounds<<"\n";
    return 0;
}