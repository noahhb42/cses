#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int a,b;cin>>a>>b;
    vvll dp(a+1,vll(b+1,(int)1e9));

    rep(i,1,a+1)dp[i][1]=i-1;
    rep(i,1,b+1)dp[1][i]=i-1;

    rep(i,2,a+1){
        rep(j,2,b+1){
            if(i==j){
                dp[i][j]=0;
                continue;
            }
            rep(k,1,i){
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            }
            rep(k,1,j){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }

    cout << dp[a][b] << endl;
}