#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0 ; i<n ; ++i)
 
ll p(ll x, ll y, ll m){
    ll ans = 1;
    while(y){
        if(y&1)ans*=x;
        ans%=m;
        x*=x;
        x%=m;
        y>>=1;
    }
    return ans;
}
 
int main(){
    ll n;cin>>n;
    cout<<p(2,n,(ll)1e9+7)<<endl;
}
