#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = 1e18;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    vector<string> g(n);
    rep(i,0,n)cin>>g[i];

    auto id = [&](ll i, ll j){return m*i+j;};
    ll s = -1;

    vll mt(n*m, INF);
    queue<ll> q;

    rep(r,0,n){
        rep(c,0,m){
            if(g[r][c]=='M'){
                mt[id(r,c)]=0;
                q.push(id(r,c));
            }
            else if(g[r][c]=='A'){
                s = id(r,c);
            }
        }
    }

    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};

    while(!q.empty()){
        ll u = q.front();q.pop();
        ll r = u/m; ll c = u%m;
        rep(k,0,4){
            ll nr = r+dr[k]; ll nc = c + dc[k];
            if(nr<0 || nr>=n || nc<0 || nc>=m)continue;
            if(g[nr][nc]=='#')continue;
            ll v = id(nr,nc);
            if(mt[v]>mt[u]+1){
                mt[v]=mt[u]+1;
                q.push(v);
            }
        }
    }

    auto is_border = [&](ll u){
        ll r = u/m; ll c = u%m;
        return r==0 || r==n-1 || c==0 || c==m-1;
    };

    if(is_border(s)){
        cout<<"YES\n0\n";
        return 0;
    }

    vll dist(n*m, INF), par(n*m, -1);
    vector<char> step(n*m, 0);
    queue<ll> qa;
    dist[s] = 0;
    qa.push(s);

    while(!qa.empty()){
        ll u = qa.front(); qa.pop();
        ll r = u/m; ll c = u%m;
        rep(k,0,4){
            ll nr = r+dr[k]; ll nc = c+dc[k];
            if(nr < 0 || nr>=n || nc<0 || nc>=m)continue;
            if(g[nr][nc]=='#')continue;
            ll v = id(nr,nc);
            if(dist[v]!=INF)continue;
            ll nt = dist[u]+1;
            if(nt>=mt[v])continue;
            dist[v] = nt;
            par[v] = u;
            step[v] = "DURL"[k];
            if(is_border(v)){
                string path = "";
                for(ll x = v ; x!= s ; x = par[x]){
                    path.push_back(step[x]);
                }
                reverse(path.begin(), path.end());
                cout << "YES\n" << path.size() << '\n' << path << '\n';
                return 0;
            }
            qa.push(v);
        }
    }

    cout<<"NO\n";
}