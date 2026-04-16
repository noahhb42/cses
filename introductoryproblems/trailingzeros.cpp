#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0 ; i<n ; ++i)
 
int main(){
    ll n;cin>>n;
    ll cnt = 0;
    ll pow = 5;
    while(n/pow){
        cnt+=n/pow;pow*=5;
    }
    cout<<cnt<<"\n";
}