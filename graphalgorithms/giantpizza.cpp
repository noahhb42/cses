#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;

    auto id = [&](ll x, bool is_neg){
        return 2*(x-1) + (is_neg ? 1 : 0);
    };

    ll V = 2*m;
    vvll g(V), gr(V);

    auto add_edge = [&](ll u, ll v){
        g[u].push_back(v);
        gr[v].push_back(u);
    };

    auto add_or = [&](ll a, bool x, ll b, bool y){
        ll A = id(a, !x);
        ll nA = id(a, x);
        ll B = id(b, !y);
        ll nB = id(b, y);
        add_edge(nA, B);
        add_edge(nB, A);
    };

    rep(i,0,n){
        char c1,c2;ll a,b;
        cin>>c1>>a>>c2>>b;
        bool pos1 = (c1=='+');
        bool pos2 = (c2=='+');
        add_or(a,pos1,b,pos2);
    }

    vll vis(V,0);
    vll order(0);
    vll it(V,-1);

    rep(s,0,V)if(!vis[s]){
        stack<ll> st;
        st.push(s);
        it[s]=0;
        vis[s]=1;
        while(!st.empty()){
            ll u = st.top();
            if(it[u]<g[u].size()){
                ll v = g[u][it[u]++];
                if(!vis[v]){
                    vis[v]=1;
                    st.push(v);
                    it[v]=0;
                }
            }
            else{
                order.push_back(u);
                st.pop();
            }
        }
    }

    vll comp(V,-1);
    vis.assign(V,0);
    ll cid = 0;
    for(ll i = V-1 ; i>=0 ; --i){
        ll s = order[i];
        if(vis[s])continue;
        stack<ll> st;
        vis[s]=1;
        comp[s]=++cid;
        st.push(s);
        while(!st.empty()){
            ll u = st.top();st.pop();
            for(auto v : gr[u])if(!vis[v]){
                vis[v]=1;
                comp[v]=cid;
                st.push(v);
            }
        }
    }

    vector<char> ans(m);
    rep(x,1,m+1){
        ll t = id(x,false);
        ll f = id(x,true);
        if(comp[t]==comp[f]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
        bool val = comp[t] > comp[f];
        ans[x-1] = val ? '+' : '-';
    }

    for(auto i : ans)cout<<i<<' ';cout<<'\n';
    return 0;
}