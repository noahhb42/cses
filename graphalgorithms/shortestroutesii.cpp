#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = 1e18;

ll dis[500][500];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,q;cin>>n>>m>>q;
    rep(i,0,500)rep(j,0,500)dis[i][j]=INF;
    rep(i,0,500)dis[i][i]=0;
    rep(i,0,m){
        ll a,b,c;cin>>a>>b>>c;
        a--;b--;
        dis[a][b]=min(dis[a][b],c);
        dis[b][a]=min(dis[b][a],c);
    }
    rep(k,0,500){
        rep(i,0,500){
            rep(j,0,500){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    rep(i,0,q){
        ll a,b;cin>>a>>b;a--;b--;
        cout<<(dis[a][b]==INF ? -1 : dis[a][b])<<"\n";
    }
}