#include"bits/stdc++.h"
using namespace std;
#define rep(i,a,n) for(int i = a ; i<n ; ++i)

int main(){
    int n;cin>>n;
    int ans = 0;
    int m = n-1;

    rep(i,0,n){
        int a;cin>>a;
        if((i&m)==i){
            ans ^= a;
        }
    }
    cout << ans << "\n";
}