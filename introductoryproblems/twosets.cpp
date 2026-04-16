#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0 ; i<n ; ++i)
 
int main(){
    int n;cin>>n;
    cin.tie(0)->sync_with_stdio(0);
    if(n%4==2||n%4==1)cout<<"NO\n";
    else{
        cout<<"YES\n";
        if(n%2){    
            cout<<n/2+1<<"\n1 2 ";
            for(int i = 4 ; i<=n ; i+=4)cout<<i<<" "<<i+3<<" ";
            cout<<"\n"<<n/2<<"\n3 ";
            for(int i = 5 ; i<=n ; i+=4)cout<<i<<" "<<i+1<<" ";
            cout<<"\n";
        }
        else{
            cout<<n/2<<"\n";
            for(int i = 1 ; i<=n ; i+=4)cout<<i<<" "<<i+3<<" ";
            cout<<"\n"<<n/2<<"\n";
            for(int i = 2 ; i<=n ; i+=4)cout<<i<<" "<<i+1<<" ";
            cout<<"\n";
        }
    }
}
