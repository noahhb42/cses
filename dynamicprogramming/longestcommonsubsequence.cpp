#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n,m;cin>>n>>m;
    vll a(n), b(m);
    rep(i,0,n)cin>>a[i];
    rep(j,0,m)cin>>b[j];

    vvll dp(n+1,vll(m+1,0));
    rep(i,1,n+1){
        rep(j,1,m+1){
            if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    vll seq(0);
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(a[i-1]==b[j-1]){
            seq.push_back(a[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(seq.begin(),seq.end());

    cout << dp[n][m] << endl;
    for(auto i : seq)cout<<i<<" ";
    cout<<endl;
}