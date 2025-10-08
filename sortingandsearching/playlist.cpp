#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    map<int,int> m{};
    set<int> s;
    ll start = 0;
    ll mx = 0;
    rep(i,0,n){
        int a;cin>>a;
        if(s.find(a)!=s.end()){
            start = max(start, (ll)m[a]+1);
        }
        mx = max(mx,i-start+1);
        m[a] = i;
        s.insert(a);
    }
    cout<<mx<<"\n";
}