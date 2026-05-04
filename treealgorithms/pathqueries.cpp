#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct SegTree{
    int n;
    vector<ll> tree;
    SegTree(int sz){
        n = 1;
        while(n < sz)n <<= 1;
        tree.assign(2*n,0);
    }
    void insert(int k, ll x){
        k += n;
        tree[k] = x;
        for(k /= 2 ; k >= 1 ; k /= 2){
            tree[k] = tree[2*k] + tree[2*k+1];
        }
    }
    ll query(int a, int b){
        a += n; b += n;
        ll s = 0;
        while(a <= b){
            if(a%2 == 1)s += tree[a++];
            if(b%2 == 0)s += tree[b--];
            a /= 2; b /= 2;
        }
        return s;
    }
};

struct HLD{
    int n, timer = 0;
    vector<vi> g;
    SegTree st;
    vi parent, depth, sub, heavy, head, pos;

    HLD(int n): n(n), g(n+1), parent(n+1), depth(n+1), sub(n+1), heavy(n+1,-1), head(n+1), pos(n+1), st(n){}

    void add_edge(int a, int b){
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int dfs_size(int u, int p){
        parent[u] = p;
        sub[u] = 1;

        int best_size = 0;

        for(int v : g[u]){
            if(v == p)continue;

            depth[v] = depth[u]+1;

            int child_size = dfs_size(v,u);
            sub[u] += child_size;

            if(child_size > best_size){
                best_size = child_size;
                heavy[u] = v;
            }

        }

        return sub[u];
    }

    void dfs_decompose(int u, int h){
        head[u] = h;
        pos[u] = timer++;

        if(heavy[u] != -1){
            dfs_decompose(heavy[u], h);
        }

        for(int v : g[u]){
            if(v == parent[u] || v == heavy[u])continue;
            dfs_decompose(v,v);
        }
    }

    void build(int root = 1){
        depth[root] = 0;
        dfs_size(root, 0);
        dfs_decompose(root, root);
    }

    void insert(int node, int x){
        st.insert(pos[node], x);
    }

    ll query(int node){
        ll s = 0;
        while(head[node] != 1){
            int h = head[node];
            s += st.query(pos[h], pos[node]);
            node = parent[h];
        }
        s += st.query(pos[1], pos[node]);
        return s;
    }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n,q;cin>>n>>q;

    HLD hld(n);
    vi val(n+1);
    rep(i,1,n+1)cin>>val[i];
    rep(i,1,n){
        int a,b;cin>>a>>b;
        hld.add_edge(a,b);
    }
    hld.build();
    rep(i,1,n+1)hld.insert(i,val[i]);

    while(q--){
        int op;cin>>op;
        if(op == 1){
            int node, x;cin>>node>>x;
            hld.insert(node,x);
        }
        else{
            int node;cin>>node;
            cout << hld.query(node) << "\n";
        }
    }
}