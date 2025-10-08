#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,x;cin>>n>>x;
    vector<int> w(n);
    rep(i,0,n)cin>>w[i];
    int i = 0, j = n-1, sm = 0;
    sort(w.begin(), w.end());
    while(i<=j){
        sm++;
        if(w[i]+w[j]<=x && i!=j){
            i++;
            j--;
        }
        else{
            j--;
        }
    }
    cout<<sm<<"\n";
}