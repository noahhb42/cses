#include"bits/stdc++.h"
using namespace std;
 
void solve(){
    int n,a,b;cin>>n>>a>>b;
    if((a==0 && b>0) || (a>0 && b==0) || a+b > n){
        cout <<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(int i = 1 ; i<=n ; ++i){
        cout<<i<<(i==n ? "\n" : " ");
    }
    for(int i = 1 ; i<=a+b ; ++i){
        cout<<(i+a-1)%(a+b)+1<<" ";
    }
    for(int i = a+b+1 ; i<= n ; ++i){
        cout<<i<<" ";
    }
    cout<<"\n";
}
 
int main(){
    int t;cin>>t;
    while(t--)solve();
}
