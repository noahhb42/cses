#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,n) for(ll i = 0 ; i<n ; ++i)

void bfs(ll si, ll sj, ll n, ll m, vector<vector<char>>& grid){
    queue<pll> q;
    q.push({si, sj});
    grid[si][sj]='E';
    while(q.size()){
        auto [x,y] = q.front();q.pop();
        if(x-1>=0 && grid[x-1][y]=='.'){
            grid[x-1][y]='U';
            q.push({x-1,y});
        }
        if(x+1<n && grid[x+1][y]=='.'){
            grid[x+1][y]='D';
            q.push({x+1,y});
        }
        if(y-1>=0 && grid[x][y-1]=='.'){
            grid[x][y-1]='L';
            q.push({x,y-1});
        }
        if(y+1<m && grid[x][y+1]=='.'){
            grid[x][y+1]='R';
            q.push({x,y+1});
        }
    }
}

int main(){
    ll n,m;cin>>n>>m;
    ll si,sj,ei,ej;
    vector<vector<char>> grid(n,vector<char>(m,'0'));
    vvll dis(n, vll(m,1e7));
    rep(i,n){
        rep(j,m){
            cin>>grid[i][j];
            if(grid[i][j]=='A'){
                si = i;
                sj = j;
            }
            if(grid[i][j]=='B'){
                ei = i;
                ej = j;
            }
        }
    }
    grid[si][sj]='.';
    grid[ei][ej]='.';

    bfs(si, sj, n, m, grid);

    if(grid[ei][ej]=='.'){
        cout<<"NO"<<endl;

    }
    else{
        cout<<"YES"<<endl;
        string s = "";
        while(ei != si || ej != sj){
            s.push_back(grid[ei][ej]);
            if(grid[ei][ej]=='R'){
                ej--;
            }
            else if(grid[ei][ej]=='L'){
                ej++;
            }
            else if(grid[ei][ej]=='U'){
                ei++;
            }
            else{
                ei--;
            }
        }
        reverse(s.begin(),s.end());
        cout<<s.size()<<endl<<s<<endl;
    }

}