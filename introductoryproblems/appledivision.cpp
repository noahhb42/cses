#include"bits/stdc++.h"
using namespace std;
 
int main(){
    int n;cin>>n;
    vector<long long> p(n);
    for(auto &i : p) cin >> i;
    
    long long mn = 1'000'000'000;
    
    for(int i = 0 ; i < (1<<n) ; ++i){
        long long sm = 0;
        for(int j = 0 ; j<n ; ++j){
            if( (1<<j) & i )sm += p[j];
            else sm-=p[j];
        }
        mn = min(abs(sm), mn);
    }
    
    cout << mn << "\n";
}