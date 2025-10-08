#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k;cin>>n>>m>>k;
    vector<int> a(n), b(m);
    rep(i,0,n)cin>>a[i];
    rep(i,0,m)cin>>b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int sm = 0, i = 0, j = 0;
    while(i<n && j<m){
        if(abs(a[i]-b[j])<=k){
            sm++;
            i++;
            j++;
        }
        else if(a[i]<b[j])i++;
        else j++;
    }
    cout<<sm<<"\n";
}