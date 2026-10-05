#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1e9+7;

vi prefcalc(string& s){
    int n = sz(s);
    vi pi(n,0);
    rep(i,1,n){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j])j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n;cin>>n;
    string s;cin>>s;
    int m = sz(s);

    vector<vector<ll>> nxt(m, vector<ll>(26,-1));
    vi p = prefcalc(s);
    rep(j,0,m){
        rep(k,0,26){
            int g = j;
            while(g > 0 && s[g] != 'A'+k)g = p[g-1];
            if(s[g] == 'A'+k)g++;
            nxt[j][k] = g;
        }
    }

    vector<vector<ll>> dp(n+1, vector<ll>(m,0));
    dp[0][0] = 1;
    rep(i,1,n+1){
        rep(j,0,m){
            rep(k,0,26){
                if(nxt[j][k]<m){
                    dp[i][nxt[j][k]] = (dp[i][nxt[j][k]] + dp[i-1][j])%mod;
                }
            }
        }
    }

    ll ans = 1;
    rep(i,0,n)ans = (ans*26)%mod;
    rep(j,0,m){
        ans = ((ans - dp[n][j])%mod + mod)%mod;
    }
    cout << ans << "\n";
}