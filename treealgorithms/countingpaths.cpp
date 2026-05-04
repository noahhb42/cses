#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void root(int node, vector<vi>& g, vi& parent, vi& depth){
    for(int child : g[node]){
        if(parent[node] == child)continue;
        parent[child] = node;
        depth[child] = depth[node]+1;
        root(child,g,parent,depth);
    }
}

int lift(int x, int k, vector<vi>& up){
    for(int i = 19 ; i>=0 ; --i){
        if((1<<i)&k)x=up[i][x];
    }
    return x;
}

int lca(int a, int b, vi& depth, vector<vi>& up){
    if(depth[a] < depth[b])swap(a,b);
    a = lift(a,depth[a]-depth[b],up);
    for(int k = 19 ; k>=0 ; --k){
        if(up[k][a] != up[k][b]){
            a = up[k][a];
            b = up[k][b];
        }
    }
    if(a == b)return a;
    return up[0][a];
}

void dfs(int node, vi& val, vi&ans, vi& parent, vector<vi>& g){

    ans[node] = val[node];

    for(int child : g[node]){
        if(parent[node] == child)continue;
        dfs(child,val,ans,parent,g);
        ans[node] += ans[child];
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n,m;cin>>n>>m;
    vector<vi> g(n+1);
    vector<vi> up(20, vi(n+1,-1));
    vi depth(n+1,0);

    rep(i,0,n-1){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    root(1,g,up[0],depth);
    rep(k,1,20){
        rep(i,2,n+1){
            if(up[k-1][i]!=-1)up[k][i]=up[k-1][up[k-1][i]];
        }
    }

    vi val(n+1,0),ans(n+1,0);

    rep(i,0,m){
        int a,b;cin>>a>>b;
        int l = lca(a,b,depth,up);
        val[a]++;
        val[b]++;
        val[l]--;
        if(up[0][l] != -1)val[up[0][l]]--;
    }

    dfs(1,val,ans,up[0],g);

    rep(i,1,n+1)cout<<ans[i]<<" ";
    cout<<"\n";
}