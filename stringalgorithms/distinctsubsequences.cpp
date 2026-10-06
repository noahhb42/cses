#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define int long long

const int mod = 1e9 + 7;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    string s;cin>>s;
    int n = sz(s);
    vector<int> dp(n+1,0);
    dp[0] = 1;
    vector<int> last(26,0);

    rep(i,1,n+1){
        if(last[s[i-1]-'a'] == 0){
            dp[i] = (dp[i] + 2*dp[i-1])%mod;
        }
        else{
            dp[i] = (dp[i] + 2*(dp[i-1]) - dp[last[s[i-1]-'a']-1])%mod;
        }
        last[s[i-1]-'a'] = i;
    }

    cout << (dp[n]-1+mod)%mod << "\n";
}