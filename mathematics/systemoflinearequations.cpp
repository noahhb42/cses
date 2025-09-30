#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mod = 1e9+7;

ll powmod(ll a,ll b){
    ll r = 1;
    a%=mod;
    b%=mod-1;
    while(b){
        if(b&1){
            r = (r*a)%mod;
        }
        a = (a*a)%mod;
        b>>=1;
    }
    return r;
}
ll inv(ll a){return powmod(a,mod-2);}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    vector<vll> mat(n, vll(m+1));
    rep(i,0,n)rep(j,0,m+1)cin>>mat[i][j];

    vll where(m,-1);
    ll row = 0;
    for(ll col = 0 ; col<m && row<n ; ++col){
        ll sel = -1;
        for(ll i = row ; i<n ; ++i)if(mat[i][col]!=0){sel=i;break;}
        if(sel==-1)continue;
        swap(mat[sel],mat[row]);
        where[col]=row;

        ll invp = inv(mat[row][col]);
        for(ll j = col ; j<=m ; ++j)mat[row][j] = (mat[row][j]*invp)%mod;

        for(ll i = 0 ; i<n ; ++i){
            if(i==row)continue;
            if(mat[i][col]!=0){
                ll factor = mat[i][col];
                for(ll j = col ; j<=m ; ++j){
                    ll val = mat[i][j] - (factor*mat[row][j])%mod;
                    if(val < 0)val+=mod;
                    mat[i][j] = val;
                }
            }
        }
        ++row;
    }

    for(ll i = 0 ; i<n ; ++i){
        bool all0 = true;
        for(ll j = 0 ; j<m ; ++j)if(mat[i][j]!=0){all0=false;break;}
        if(all0 && mat[i][m]){cout<<"-1\n";return 0;}
    }

    vll x(m,0);

    for(ll j = 0 ; j<m ; ++j)if(where[j]!=-1)x[j]=mat[where[j]][m];

    for(ll j = 0 ; j<m ; ++j){
        if(j)cout<<' ';
        cout<<x[j];
    }
    cout<<"\n";
}