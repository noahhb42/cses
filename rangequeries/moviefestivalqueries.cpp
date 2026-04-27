#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct Movie{
    ll l,r;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n,q;cin>>n>>q;
    vector<Movie> mv(n);
    ll exp = 64 - __builtin_clzll(n);
    vvll up(n, vll(exp, n));
    ll sufmax = 0;
    rep(i,0,n){
        cin >> mv[i].l >> mv[i].r;
        sufmax = max(sufmax, mv[i].r+1);
    }
    sort(mv.begin(),mv.end(),[&](const Movie &m1, const Movie &m2){
        return m1.r < m2.r;
    });

    queue<ll> Q;
    rep(i,0,n){
        while(!Q.empty() && mv[Q.front()].r <= mv[i].l){
            up[Q.front()][0] = i;
            Q.pop();
        }
        Q.push(i);
    }

    for(ll e = 1 ; e<exp ; ++e){
        rep(i,0,n){
            if(up[i][e-1]<n)up[i][e]=up[up[i][e-1]][e-1];
        }
    }

    vector<pair<ll,ll>> start(n);
    rep(i,0,n)start[i] = {mv[i].l, i};
    sort(start.begin(),start.end());

    vll suf(n+1,n);
    for(ll i = n-1 ; i>= 0 ; --i){
        ll cur = start[i].second;
        ll best = suf[i+1];
        if(best == n || mv[cur].r < mv[best].r){
            suf[i] = cur;
        }
        else{
            suf[i] = best;
        }
    }

    rep(i,0,q){
        ll a,b;cin>>a>>b;
        ll pos = lower_bound(start.begin(), start.end(), make_pair(a,-1LL)) - start.begin();
        ll cur = suf[pos];
        if(cur == n || mv[cur].r > b){
            cout << 0 << "\n";
            continue;
        }
        ll ans = 1;
        for(ll e = exp-1 ; e>=0 ; --e){
            if(up[cur][e]<n && mv[up[cur][e]].r<=b){
                cur = up[cur][e];
                ans += 1<<e;
            }
        }
        cout << ans << "\n";
    }
}