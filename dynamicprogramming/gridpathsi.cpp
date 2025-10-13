#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

constexpr ll MOD = 1e9+7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    vector<string> grid(n);
    rep(i,0,n)cin>>grid[i];
    vvll dp(n,vll(n,0));
    vvll vis(n,vll(n,0));
    queue<array<ll,2>> q;
    if(grid[0][0]=='.'){dp[0][0]=1;q.push({0,0});}
    while(q.size()){
        auto [x,y] = q.front();q.pop();
        if(vis[x][y])continue;
        vis[x][y]=1;
        if(x+1<n && grid[x+1][y]=='.'){dp[x+1][y]+=dp[x][y];dp[x+1][y]%=MOD;q.push({x+1,y});}
        if(y+1<n && grid[x][y+1]=='.'){dp[x][y+1]+=dp[x][y];dp[x][y+1]%=MOD;q.push({x,y+1});}
    }
    cout<<dp[n-1][n-1]<<"\n";
}