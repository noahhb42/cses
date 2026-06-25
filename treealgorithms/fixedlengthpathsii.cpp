#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define rep(i,a,n) for(int i = a ; i<n ; ++i)
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
 
int n,a,b;
const int mxn = 2e5+5;
bool removed[mxn];
int sub[mxn], cnt[mxn], pref[mxn];
 
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
    if(depth > b)return;
    depths.push_back(depth);
    for(auto v : g[u]){
        if(v==p || removed[v])continue;
        collect_depths(v,u,depth+1,depths);
    }
}
 
ll count_pairs(vi& depths){
    if(depths.empty())return 0;
 
    ll mx = 0;
    for(auto d : depths)mx=max(mx,(ll)d);
 
    for(auto d : depths)cnt[d]=0;
 
    for(auto d : depths)cnt[d]++;
 
    pref[0]=cnt[0];
    rep(i,1,mx+1){
        pref[i] = pref[i-1]+cnt[i];
    }
 
    ll ordered = 0;
    ll self = 0;
 
    for(auto d : depths){
        ll lo = a-d;
        ll hi = b-d;
 
        lo = max(0LL,lo);
        hi = min(hi,mx);
 
        if(lo <= hi){
            ordered += pref[hi] - (lo ? pref[lo-1] : 0);
        }
 
        if(a <= 2*d && 2*d <= b){
            self++;
        }
    }
    
    for(auto d : depths)cnt[d]=0;
    rep(i,0,mx+1)pref[i]=0;
 
    return (ordered - self)/2;
}
 
void solve(int u = 0){
    calc_subtree(u,-1);
 
    int c = get_centroid(u,-1,sub[u]);
    removed[c] = true;
 
    vi all_depths;
    all_depths.push_back(0);
 
    for(auto v : g[c]){
        if(removed[v])continue;
 
        vi depths;
        collect_depths(v,c,1,depths);
 
        ans-=count_pairs(depths);
 
        for(auto d : depths){
            all_depths.push_back(d);
        }
    }
 
    ans += count_pairs(all_depths);
 
    for(auto v : g[c]){
        if(!removed[v]){
            solve(v);
        }
    }
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>a>>b;
    rep(i,1,n){
        int u,v;cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    solve();
 
    cout << ans << "\n";
}