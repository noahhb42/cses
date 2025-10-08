#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)
#define all(a) (a).begin(), (a).end()

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    vll a(n), b(n);
    rep(i,0,n)cin>>a[i]>>b[i];
    sort(all(a));sort(all(b));
    int i = 0, j = 0;
    int mx = 0;
    while(i<n && j<n){
        if(a[i]<b[j]){
            i++;
        }
        else j++;
        mx = max(mx, i-j);
    }
    cout<<mx<<"\n";
}