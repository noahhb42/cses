#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0 ; i<n ; ++i)
 
int main(){
    ll n;cin>>n;
    ll sm = 0;
    ll mx = 0;
    rep(i,n){
        ll a;cin>>a;
        if(i==0)mx=a;
        else{
            sm+=max(mx-a,0ll);
            mx = max(a,mx);
        }
    }
    cout<<sm<<endl;
}