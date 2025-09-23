#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,n) for(ll i = 0 ; i<n ; ++i)

ll counter = 1;

void bfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, vector<vll>& nr, ll n, ll m, ll x, ll y){
    queue<array<ll,2>> q;
    q.push({x,y});
    nr[x][y] = counter;
    vis[x][y] = true;
    while(!q.empty()){
        auto [xx,yy] = q.front();q.pop();
        for(ll i = xx-1 ; i<xx+2 ; ++i){
            for(ll j = yy-1 ; j<yy+2 ; ++j){
                if((abs(i-xx)+abs(j-yy))!=1)continue;
                if(i<0 || i>=n || j<0 || j>=m)continue;
                if(vis[i][j])continue;
                if(grid[i][j]=='#')continue;
                vis[i][j] = true;
                nr[i][j] = counter;
                q.push({i,j});
            }
        }
    }
    counter++;
}

int main(){
    ll n,m;cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m,'0'));
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    vector<vll> nr(n, vll(m,0));
    rep(i,n)rep(j,m)cin>>grid[i][j];
    
    rep(i,n){
        rep(j,m){
            if(grid[i][j]=='#' || vis[i][j]==true)continue;
            bfs(grid, vis, nr, n, m, i, j);
        }
    }

    ll mx = 0;
    rep(i,n)rep(j,m)mx=max(mx,nr[i][j]);

    cout << mx << endl;
}