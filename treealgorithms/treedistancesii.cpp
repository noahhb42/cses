#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n;

void dfs1(int node, vector<vi>& g, vector<ll>& sub, vector<ll>& sum_child, vi& parent){
    for(int child : g[node]){
        if(parent[node] == child)continue;

        parent[child] = node;
        dfs1(child, g, sub, sum_child, parent);
        sub[node] += sub[child] + 1;
    }
    sum_child[node] = sub[node];
    for(int child : g[node]){
        if(parent[node] == child)continue;

        sum_child[node] += sum_child[child];
    }
}

void dfs2(int node, vector<vi>& g, vector<ll>& sub, vector<ll>& sum_child, vector<ll>& sum_all, vi& parent){
    for(int child : g[node]){
        if(parent[node] == child)continue;

        ll sum_other = sum_all[node] - (sum_child[child] + sub[child] + 1);
        sum_all[child] = sum_child[child] + sum_other + (n - sub[child] - 1);

        dfs2(child, g, sub, sum_child, sum_all, parent);
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n;
    vector<vi> g(n+1,vi(0));
    rep(i,0,n-1){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vi parent(n+1,0);
    parent[1] = 1;

    vector<ll> sub(n+1,0), sum_child(n+1,0), sum_all(n+1,0);
    dfs1(1, g, sub, sum_child, parent);
    sum_all[1] = sum_child[1];
    dfs2(1, g, sub, sum_child, sum_all, parent);

    rep(i,1,n+1)cout<<sum_all[i]<<" ";
    cout<<"\n";
}