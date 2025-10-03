#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

ll board[8][8];
const ll dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const ll dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool inside(ll x, ll y){
    return x>=0 && x<8 && y>=0 && y<8;
}

ll degree(ll x, ll y){
    ll c = 0;
    rep(k,0,8){
        ll nx = x+dx[k], ny = y+dy[k];
        if(inside(nx,ny) && board[ny][nx]==0)c++;
    }
    return c;
}

bool dfs(ll x, ll y, ll step){
    board[y][x] = step;
    if(step==64)return true;

    vector<array<ll,2>> cand;
    ll cnt = 0;
    rep(k,0,8){
        ll nx = x+dx[k], ny = y+dy[k];
        if(inside(nx,ny) && board[ny][nx]==0){
            cnt++;
            cand.push_back({degree(nx,ny), k});
        }
    }
    sort(cand.begin(), cand.end());

    rep(i,0,cnt){
        ll k = cand[i][1];
        ll nx = x+dx[k], ny = y +dy[k];
        if(dfs(nx,ny,step+1))return true;
    }

    board[y][x]=0;
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll x,y;
    cin>>x>>y;
    dfs(x-1,y-1,1);

    rep(r,0,8){
        rep(c,0,8){
            cout<<board[r][c]<<(c==7 ? '\n' : ' ');
        }
    }
    return 0;
}