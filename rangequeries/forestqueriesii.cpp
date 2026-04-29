#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct Fenwick{
    ll n;
    vvll bit;

    Fenwick(ll sz){
        n = sz;
        bit.assign(n+1,vll(n+1,0));
    }

    void insert(ll i,ll j, ll x){
        for(ll k = i ; k <= n ; k += k&-k){
            for(ll l = j ; l <= n ; l += l&-l){
                bit[k][l] += x;
            }
        }
    }

    ll sum(ll a, ll b){
        ll s = 0;
        for(ll i = a ; i>=1 ; i-=i&-i){
            for(ll j = b ; j>=1 ; j-=j&-j){
                s += bit[i][j];
            }
        }
        return s;
    }

    ll query(ll a, ll b, ll c, ll d){
        if(a>c)swap(a,c);
        if(b>d)swap(b,d);
        return sum(c,d) - sum(a-1,d) - sum(c,b-1) + sum(a-1,b-1);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll n,q;cin>>n>>q;
    Fenwick tree(n);
    vvll grid(n+1,vll(n+1,0));
    rep(i,0,n){
        rep(j,0,n){
            char c;cin>>c;
            if(c=='*'){
                tree.insert(i+1,j+1,1);
                grid[i+1][j+1] = 1;
            }
        }
    }

    rep(i,0,q){
        ll op;cin>>op;
        if(op == 1){
            ll a,b;cin>>a>>b;
            if(grid[a][b] == 1){
                tree.insert(a,b,-1);
            }
            else{
                tree.insert(a,b,1);
            }
            grid[a][b] = 1 - grid[a][b];
        }
        else{
            ll a,b,c,d;cin>>a>>b>>c>>d;
            cout << tree.query(a,b,c,d) << "\n";
        }
    }
}