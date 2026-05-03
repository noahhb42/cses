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
    vi p(n+1,0), count(n+1,0), ans(n+1,0);
    rep(i,2,n+1){
        ll a;cin>>a;
        p[i]=a;
        count[a]++;
    }
    vi order;
    queue<ll> q;
    rep(i,1,n+1){
        if(count[i]==0)q.push(i);
    }
    while(!q.empty()){
        int u = q.front();q.pop();
        order.push_back(u);
        if(--count[p[u]]==0)q.push(p[u]);
    }
    for(auto u : order){
        if(u==1)continue;
        ans[p[u]]+=ans[u]+1;
    }
    rep(i,1,n+1)cout<<ans[i]<<" ";
    cout<<"\n";
}