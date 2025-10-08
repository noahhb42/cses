#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    vector<array<int,2>> a(n);
    rep(i,0,n){
        int b,c;cin>>b>>c;
        a[i] = {c,b};
    }
    sort(a.begin(), a.end());
    int le = -1;
    int sm = 0;
    for(auto [x,y] : a){
        if(le <= y){
            le = x;
            sm++;
        }
    }
    cout<<sm<<"\n";
}