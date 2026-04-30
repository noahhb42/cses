#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll inf = (ll)1e18;

struct Project{
    ll start, end, profit;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;cin>>n;
    vector<Project> ps(n);
    rep(i,0,n)cin>>ps[i].start>>ps[i].end>>ps[i].profit;

    auto cmp = [](const Project& p1, const Project& p2){
        return p1.end < p2.end;
    };

    sort(ps.begin(), ps.end(), cmp);

    vll dp(n,0);
    dp[0] = ps[0].profit;
    rep(i,1,n){
        Project search = {-inf, ps[i].start, -inf};
        ll ind = (lower_bound(ps.begin(),ps.end(),search, cmp)-ps.begin()) - 1;
        if(ind < 0)dp[i] = ps[i].profit;
        else dp[i] = dp[ind] + ps[i].profit;
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n-1] << "\n";
}