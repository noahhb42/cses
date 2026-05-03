#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void dfs(int node, vector<vi>& children, vi& ans){
    for(auto child : children[node]){
        dfs(child,children,ans);
        ans[node]+=ans[child]+1;
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll n;cin>>n;
    vector<vi> children(n+1,vi(0));
    vi ans(n+1,0);
    rep(i,2,n+1){
        ll u;cin>>u;
        children[u].push_back(i);
    }
    dfs(1,children,ans);
    rep(i,1,n+1)cout<<ans[i]<<" ";
    cout<<"\n";
}