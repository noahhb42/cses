#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int timer = 1;
const int mxn = 2e5+5;
int tin[mxn], tout[mxn], parent[mxn];
vi g[mxn];

void root(int node){
    tin[node] = timer++;
    for(auto child : g[node]){
        if(parent[node] == child)continue;
        parent[child] = node;
        root(child);
    }
    tout[node] = timer-1;
}

struct SegTree{
    int n;
    vector<ll> tree;
    SegTree(int sz){
        n = 1;
        while(n < sz)n <<= 1;
        tree.assign(2*n,0);
    }

    void insert(int k, int x){
        k += n;
        tree[k] = x;
        for(k /= 2 ; k >= 1 ; k /= 2){
            tree[k] = tree[2*k] + tree[2*k+1];
        }
    }

    ll query(int L, int R){
        L += n;
        R += n;
        ll s = 0;
        while(L <= R){
            if(L%2 == 1)s += tree[L++];
            if(R%2 == 0)s += tree[R--];
            L /= 2;
            R /= 2;
        }
        return s;
    }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    
    int n,q;cin>>n>>q;
    vi val(n+1);
    rep(i,1,n+1)cin>>val[i];
    SegTree st(n);

    rep(i,0,n-1){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    root(1);
    rep(i,1,n+1)st.insert(tin[i],val[i]);

    while(q--){
        int op;cin>>op;
        if(op == 1){
            int k,x;cin>>k>>x;
            st.insert(tin[k],x);
        }
        else{
            int k;cin>>k;
            cout << st.query(tin[k], tout[k]) << "\n";
        }
    }
}