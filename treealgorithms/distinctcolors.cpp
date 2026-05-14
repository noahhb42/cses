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
    vi tree;
    
    SegTree(int sz){
        n = 1;
        while(n < sz)n*=2;
        tree.assign(2*n,0);
    }

    void insert(int k, int x){
        k += n;
        tree[k] = x;
        for(k /= 2 ; k >= 1 ; k /= 2){
            tree[k] = tree[2*k]+tree[2*k+1];
        }
    }

    int query(int a, int b){
        a += n;
        b += n;
        int s = 0;
        while(a <= b){
            if(a%2 == 1)s += tree[a++];
            if(b%2 == 0)s += tree[b--];
            a >>= 1;
            b >>= 1;
        }
        return s;
    }
};

struct Query{
    int l, r, id;
};

const int mxn = 2e5+5;
int timer = 0;
int parent[mxn], tin[mxn], tout[mxn], euler[mxn];
vi g[mxn];

void root(int node = 0){
    tin[node] = timer++;
    euler[tin[node]] = node;
    for(auto v : g[node]){
        if(parent[node] == v)continue;
        parent[v] = node;
        root(v);
    }
    tout[node] = timer-1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;cin>>n;
    vi colors(n);
    rep(i,0,n)cin>>colors[i];
    rep(i,0,n-1){
        int a,b;cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    parent[0] = 0;
    root();

    vector<Query> qs;
    rep(i,0,n){
        qs.push_back({tin[i], tout[i], i});
    }
    auto cmp = [&](const Query& q1, const Query& q2){
        if(q1.r != q2.r)return q1.r < q2.r;
        return q1.l < q2.l;
    };
    sort(all(qs),cmp);

    vi ans(n,0);
    map<int,int> last;
    SegTree st(n);

    int i = 0;
    for(auto [l,r,id] : qs){
        while(i <= r){
            if(last.find(colors[euler[i]]) != last.end()){
                st.insert(last[colors[euler[i]]],0);
            }
            last[colors[euler[i]]] = i;
            st.insert(i,1);
            i++;
        }
        ans[id] = st.query(l,r);
    }

    rep(i,0,n)cout<<ans[i]<<" ";
    cout<<"\n";
}