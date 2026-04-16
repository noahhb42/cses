#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0 ; i<n ; ++i)
 
void testCase(){
    int a,b;cin>>a>>b;
    if((a+b)%3)cout<<"NO\n";
    else if(max(a,b)>2*min(a,b))cout<<"NO\n";
    else cout<<"YES\n";
}
 
int main(){
    int t;cin>>t;
    cin.tie(0)->sync_with_stdio(0);
    while(t--)testCase();
}