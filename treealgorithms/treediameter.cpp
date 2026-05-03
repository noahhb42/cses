#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


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

    queue<int> q;
    vector<int> dis(n+1,-1);
    q.push(1);
    dis[1]=0;

    //bfs 1
    while(!q.empty()){
        int u = q.front();q.pop();
        for(auto v : g[u]){
            if(dis[v] < 0){
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }

    int mxdis = -1, node = -1;
    rep(i,1,n+1){
        if(dis[i] > mxdis){
            mxdis = dis[i];
            node = i;
        }
    }

    dis.assign(n+1,-1);
    q.push(node);
    dis[node] = 0;

    //bfs 2
    while(!q.empty()){
        int u = q.front();q.pop();
        for(auto v : g[u]){
            if(dis[v] < 0){
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }

    int diameter = -1;
    rep(i,1,n+1)diameter = max(diameter, dis[i]);

    cout << diameter << "\n";
}