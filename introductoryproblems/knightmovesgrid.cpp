#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    ll n;cin>>n;
    vvll ans(n,vll(n,-1));
    ans[0][0]=0;
    queue<pll> q;q.push({0,0});
    pll d[8] = {{-1,-2}, {-1,2}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {2,1}, {2,-1}};
    while(!q.empty()){
        auto [x,y] = q.front();q.pop();
        for(auto [dx,dy] : d){
            ll nx = x+dx, ny = y+dy;
            if(nx < 0 || nx>=n || ny<0 || ny>=n)continue;
            if(ans[nx][ny]>-1)continue;
            ans[nx][ny] = ans[x][y]+1;
            q.push({nx,ny});
        }
    }
    rep(i,0,n){
        rep(j,0,n){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}