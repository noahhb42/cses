#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void dfs(int node, vector<vi>& g, vi& depth, vector<vi>& up){
    for(int child : g[node]){
        if(up[node][0] == child)continue;
        up[child][0] = node;
        depth[child]=depth[node]+1;
        dfs(child,g,depth,up);
    }
}

int lift(int x, int k, vector<vi>& up){
    for(int i = 19 ; i>=0 ; --i){
        if(k & (1<<i))x = up[x][i];
    }
    return x;
}

int lca(int a, int b, vector<vi>& up, vi& depth){
    if(depth[a] < depth[b])swap(a,b);
    a = lift(a, depth[a]-depth[b], up);
    for(int k = 19 ; k>=0 ; --k){
        if(up[a][k] != up[b][k]){
            a = up[a][k];
            b = up[b][k];
        }
    }
    if(a == b)return a;
    return up[a][0];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n,q;cin>>n>>q;
    vector<vi> up(n+1,vi(20,-1)), g(n+1,vi(0));
    vi depth(n+1,0);
    rep(i,1,n){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,g,depth,up);

    rep(k,1,20){
        rep(i,2,n+1){
            if(up[i][k-1]!=-1)up[i][k]=up[up[i][k-1]][k-1];
        }
    }

    while(q--){
        int a,b;cin>>a>>b;
        int p = lca(a,b,up,depth);
        cout << depth[a] + depth[b] - 2*depth[p] << "\n";
    }
}