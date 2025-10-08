#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin>>n>>m;
    multiset<int> s;
    rep(i,0,n){int a;cin>>a;s.insert(a);}
    rep(i,0,m){
        int a;cin>>a;
        auto x = s.upper_bound(a);
        if(x == s.begin()){
            cout<<-1<<"\n";
            continue;
        }
        --x;
        cout<<*x<<"\n";
        s.erase(x);
    }
}