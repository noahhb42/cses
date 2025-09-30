#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n,m;cin>>n>>m;
    vvll grid(n+1,vll(0));
    rep(i,0,m){
        ll a,b;cin>>a>>b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }

    vll parent(n+1, -1), iter(n+1, 0), state(n+1, 0);

    rep(s,1,n+1)if(state[s]==0){
        stack<ll> st;
        st.push(s);
        state[s] = 1;
        parent[s] = 0;

        while(!st.empty()){
            ll u = st.top();
            if(iter[u]==(int)grid[u].size()){
                state[u] = 2;
                st.pop();
                continue;
            }

            ll v = grid[u][iter[u]++];
            if(v == parent[u])continue;

            if(state[v]==0){
                parent[v] = u;
                state[v] = 1;
                st.push(v);
            }
            else if(state[v]==1){
                vll cyc(0);
                cyc.push_back(v);
                ll x = u;
                while(x!=v){
                    cyc.push_back(x);
                    x = parent[x];
                }
                cyc.push_back(v);
                cout<<(int)cyc.size()<<'\n';
                for(auto i : cyc)cout<<i<<' ';cout<<'\n';
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}