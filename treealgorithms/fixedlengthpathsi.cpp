#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define rep(i,a,n) for(int i = a ; i<n ; ++i)
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
 
int n,k;
const int mxn = 2e5+5;
bool removed[mxn];
int sub[mxn];
int cnt[mxn];   
 
vi g[mxn];
 
ll ans = 0;
 
void calc_subtree(int u = 0, int p = 0){
    sub[u]=1;
    for(auto v : g[u]){
        if(v==p || removed[v])continue;
        calc_subtree(v,u);
        sub[u]+=sub[v];
    }
}
 
int get_centroid(int u = 0, int p = 0, int total=0){
    for(auto v : g[u]){
        if(v==p || removed[v])continue;
        if(sub[v]*2>total)return get_centroid(v,u,total);
    }
    return u;
}
 
void collect_depths(int u, int p, int depth, vi& depths){
    if(depth > k)return;
    depths.push_back(depth);
    for(auto v : g[u]){
        if(v==p || removed[v])continue;
        collect_depths(v,u,depth+1,depths);
    }
}
 
void solve(int u = 0){
    calc_subtree(u,-1);
 
    int c = get_centroid(u,-1,sub[u]);
    removed[c] = true;
 
    vi touched;
 
    cnt[0] = 1;
    touched.push_back(0);
 
    for(auto v : g[c]){
        if(removed[v])continue;
 
        vi depths;
        collect_depths(v,c,1,depths);
 
        for(auto d : depths){
            ans += cnt[k-d];
        }
 
        for(auto d : depths){
            if(cnt[d]==0)touched.push_back(d);
            cnt[d]++;
        }
    }
 
    for(auto d : touched)cnt[d]=0;
 
    for(auto v : g[c]){
        if(!removed[v]){
            solve(v);
        }
    }
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k;
    rep(i,1,n){
        int u,v;cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    solve();
 
    cout << ans << "\n";
}
