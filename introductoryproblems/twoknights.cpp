#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0 ; i<n ; ++i)
 
int main(){
    int n;cin>>n;
    for(int i = 1 ; i<=n ; ++i)cout<<(ll)i*i*(i*i-1)/2-((2*i-3)*(2*i-3)-1)<<"\n";
}