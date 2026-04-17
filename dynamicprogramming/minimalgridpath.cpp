#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;cin>>n;
    vector<string> g(n);
    for(auto&i:g)cin>>i;

    vvll dp(n+1,vll(n+1,n+5));
    dp[n-1][n-1]=1;

    for(int diag = 2*n-3 ; diag>=0 ; --diag){
        vector<pair<int,int>> cur;
        rep(i,0,n){
            int j = diag - i;
            if(0 <= j && j<n){
                cur.emplace_back(i,j);
            }
        }
        int k = cur.size();
        vector<pair<int,int>> order;
        rep(ind,0,k){
            auto [i,j] = cur[ind];
            int s = (g[i][j]-'A')*(n+10)+min(dp[i+1][j],dp[i][j+1]);
            order.emplace_back(s,i);
        }
        sort(order.begin(),order.end());
        int val = 0;
        for(int i = 0 ; i<k ; ++i){
            if(i==0 || order[i].first != order[i-1].first){
                val++;
            }
            int r = order[i].second;
            int c = diag-r;
            dp[r][c] = val;
        }
    }

    int i = 0, j = 0;
    cout<<g[i][j];
    while(i < n-1 || j < n-1){
        if(dp[i+1][j] < dp[i][j+1]){
            i++;
        }
        else{
            j++;
        }
        cout<<g[i][j];
    }
    cout<<endl;
}