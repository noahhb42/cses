#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    set<int> s;
    rep(i,0,n){
        int a;cin>>a;
        s.insert(a);
    }
    cout<<s.size()<<"\n";
}