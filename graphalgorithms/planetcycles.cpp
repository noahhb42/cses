#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll LOG = 31;

ll jump(ll x, ll k, vvll& up){
    rep(b,0,LOG)if(k & (1<<b))x = up[b][x];
    return x;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    
    vvll up(LOG, vll(n+1));
    vll nxt(n+1);
    vvll rev(n+1);
    vll indeg(n+1,0);

    rep(i,1,n+1){
        ll t;cin>>t;
        nxt[i]=t;
        up[0][i]=t;
        rev[t].push_back(i);
        ++indeg[t];
    }

    rep(j,1,LOG){
        rep(i,1,n+1){
            up[j][i]=up[j-1][up[j-1][i]];
        }
    }

    queue<ll> qq;
    rep(i,1,n+1)if(indeg[i]==0)qq.push(i);
    while(!qq.empty()){
        ll u = qq.front();qq.pop();
        ll v = nxt[u];
        if(--indeg[v]==0)qq.push(v);
    }

    vll comp(n+1,-1), pos(n+1,-1), oncyc(n+1,0);
    vll cyclen(0);
    ll cid = 0;

    rep(i,1,n+1)if(indeg[i]>0 && comp[i]==-1){
        ll u = i, p = 0;
        do{
            comp[u]=cid;
            pos[u] = p++;
            oncyc[u] = 1;
            u = nxt[u];
        } while(u != i);
        cyclen.push_back(p);
        cid++;
    }

    vll depth(n+1, -1), entry(n+1, -1);
    queue<ll> qbfs;
    rep(i,1,n+1)if(oncyc[i]){
        depth[i]=0;
        entry[i]=i;
        qbfs.push(i);
    }
    while(!qbfs.empty()){
        ll u = qbfs.front();qbfs.pop();
        for(auto v : rev[u])if(depth[v]==-1){
            depth[v]=depth[u]+1;
            comp[v]=comp[u];
            entry[v]=entry[u];
            qbfs.push(v);
        }
    }

    rep(i,1,n+1)cout<<depth[i]+cyclen[comp[i]]<<' ';cout<<'\n';
}