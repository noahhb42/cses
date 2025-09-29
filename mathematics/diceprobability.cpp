#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll n,a,b;cin>>n>>a>>b;
    vector<long double> prev(6*n+1, 0), curr(6*n+1, 0);
    prev[0] = 1;
    for(int i = 1 ; i<=n ; ++i){
        fill(curr.begin(), curr.end(), 0);
        for(int s = i-1 ; s<= 6*(i-1); ++s){
            if(prev[s]==0)continue;
            for(int k = 1 ; k<=6 ; ++k){
                curr[s+k] += prev[s];
            }
        }
        swap(prev,curr);
    }

    long double total = pow((long double)6, n);
    long double nr = 0;

    for(int s = a ; s<= b ; ++s){
        nr+=prev[s];
    }
    cout.precision(6);
    cout<<fixed<<nr/total<<"\n";
}
