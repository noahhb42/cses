#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mxn = 2e5+5;
int n;
int parent[mxn], sz[mxn];
vi g[mxn];

void root(int node = 0){
    sz[node] = 1;
    for(auto v : g[node]){
        if(parent[node] == v)continue;

        parent[v] = node;
        root(v);
        sz[node] += sz[v];
    }
}

int centroid(int node = 0){
    for(auto v : g[node]){
        if(parent[node] == v)continue;
        
        if(sz[v]*2 > n)return centroid(v);
    }
    return node;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin>>n;
    rep(i,1,n){
        int a,b;cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    root();
    cout << centroid() + 1 << "\n";
}