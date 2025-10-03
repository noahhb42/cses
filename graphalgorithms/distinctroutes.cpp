#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = 1e18;

struct Dinic {
    struct Edge {
        ll to, rev, cap;
        bool is_rev;
    };
    ll n, s, t;
    vector<vector<Edge>> g;
    vll level, it;

    Dinic(ll n): n(n), g(n), level(n), it(n) {}

    void add_edge(ll u, ll v, ll c) {
        Edge a{v, (ll)g[v].size(), c, false};
        Edge b{u, (ll)g[u].size(), 0, true};
        g[u].push_back(a);
        g[v].push_back(b);
    }

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        queue<ll> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            ll u = q.front(); q.pop();
            for (auto &e : g[u]) if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
        return level[t] >= 0;
    }

    ll dfs(ll u, ll f) {
        if (u == t) return f;
        for (ll &i = it[u]; i < (int)g[u].size(); ++i) {
            Edge &e = g[u][i];
            if (e.cap > 0 && level[e.to] == level[u] + 1) {
                int ret = dfs(e.to, min(f, e.cap));
                if (ret > 0) {
                    e.cap -= ret;
                    g[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }

    ll maxflow(ll S, ll T) {
        s = S; t = T;
        ll flow = 0, pushed;
        while (bfs()) {
            fill(it.begin(), it.end(), 0);
            while ((pushed = dfs(s, INF)) > 0) flow += pushed;
        }
        return flow;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    Dinic D(n + 1);
    vector<array<ll,2>> edges;
    edges.reserve(m);
    rep(i,0,m) {
        ll a, b; cin >> a >> b;
        D.add_edge(a, b, 1);
    }

    ll k = D.maxflow(1, n);
    cout << k << "\n";

    vector<vector<pair<ll,ll>>> used(n + 1);
    for (ll u = 1; u <= n; ++u) {
        for (auto &e : D.g[u]) {
            if(e.is_rev)continue;   
            ll flow = D.g[e.to][e.rev].cap;
            if (flow > 0) used[u].push_back({e.to, flow});
        }
    }

    vll path;
    function<bool(ll)> getPath = [&](ll u) -> bool {
        if (u == n) return true;
        for (auto &pr : used[u]) {
            ll v = pr.first, &cnt = pr.second;
            if (cnt == 0) continue;
            cnt--;
            path.push_back(v);
            if (getPath(v)) return true;
            path.pop_back();
            cnt++;
        }
        return false;
    };

    rep(i,0,k) {
        path.clear();
        path.push_back(1);
        bool ok = getPath(1);
        cout << (ll)path.size() << "\n";
        for(auto j : path)cout<<j<<' ';cout<<'\n';
    }
    return 0;
}
