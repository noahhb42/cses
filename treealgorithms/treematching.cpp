#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void dfs(int node, vector<vi>& g, vector<pii>& ans, vi& parent){

    int sm = 0;

    for(int child : g[node]){
        if(child == parent[node])continue;
        parent[child] = node;
        dfs(child, g, ans, parent);
        sm += max(ans[child].first, ans[child].second);
    }

    ans[node].first = sm;
    for(int child : g[node]){
        if(child == parent[node])continue;
        ans[node].second = max(ans[node].second, sm - max(ans[child].first, ans[child].second) + ans[child].first + 1);
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll n;cin>>n;
    vector<vi> g(n+1,vi(0));
    rep(i,0,n-1){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vi parent(n+1,0);
    parent[1] = 1;
    vector<pii> ans(n+1,make_pair(0,0));
    dfs(1,g,ans,parent);

    cout << max(ans[1].first, ans[1].second) << "\n";
}