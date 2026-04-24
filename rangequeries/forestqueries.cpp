#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll n,q;cin>>n>>q;
    vvll g(n+1,vll(n+1,0));
    rep(i,1,n+1){
        string s;
        cin>>s;
        rep(j,1,n+1){
            g[i][j] = g[i-1][j]+g[i][j-1]-g[i-1][j-1];
            if(s[j-1]=='*')g[i][j]++;
        }
    }
    rep(_,0,q){
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2)swap(x1,x2);
        if(y1 > y2)swap(y1,y2);
        cout << g[x2][y2] - g[x1-1][y2] - g[x2][y1-1] + g[x1-1][y1-1] << "\n";
    }
}