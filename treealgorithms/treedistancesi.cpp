#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void dfs(int node, vector<vi>& g, vi& dis1, vi& dis2, vi& parent){
    for(int child : g[node]){
        if(parent[node] == child)continue;
        parent[child] = node;
        dfs(child, g, dis1, dis2, parent);
        if(dis1[child]+1 >= dis1[node]){
            dis2[node] = dis1[node];
            dis1[node] = dis1[child]+1;
        }
        else if(dis1[child]+1 > dis2[node]){
            dis2[node] = dis1[child]+1;
        }
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

    vi dis1(n+1,0), dis2(n+1,0), parent(n+1,0);
    parent[1] = 1;
    dfs(1, g, dis1, dis2, parent);

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int v : g[u]){
            if(parent[u] == v)continue;
            q.push(v);
        }

        if(u != 1){
            int p = parent[u];
            if(dis1[u] + 1 == dis1[p]){
                if(dis2[p] + 1 >= dis1[u]){
                    dis2[u] = dis1[u];
                    dis1[u] = dis2[p] + 1;
                }
                else if(dis2[p] + 1 > dis2[u]){
                    dis2[u] = dis2[p] + 1;
                }
            }
            else{
                if(dis1[p] + 1 >= dis1[u]){
                    dis2[u] = dis1[u];
                    dis1[u] = dis1[p] + 1;
                }
                else if(dis1[p] + 1 > dis2[u]){
                    dis2[u] = dis1[p] + 1;
                }
            }
        }
    }

    rep(i,1,n+1)cout<<dis1[i]<<" ";
    cout<<"\n";
}