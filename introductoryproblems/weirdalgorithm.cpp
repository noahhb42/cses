#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0 ; i<n ; ++i)
 
int main(){
    ll n;cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n%2)n=3*n+1;
        else n/=2;
        cout<<n<<" ";
    }
    cout<<"\n";
}