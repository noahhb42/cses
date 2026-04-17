#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string a,b;cin>>a>>b;
    int n = a.size(), m = b.size();
    vvll dp(n+1, vll(m+1,0));
    rep(i,0,n+1)dp[i][0]=i;
    rep(i,0,m+1)dp[0][i]=i;

    rep(i,1,n+1){
        rep(j,1,m+1){
            if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
        }
    }

    cout << dp[n][m] << endl;
}