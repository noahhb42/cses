#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

vll digits;
ll dp[20][11][2][2];
bool seen[20][11][2][2];

ll dfs(ll pos, ll prev, bool tight, bool started){
    if(pos == digits.size())return 1;
    if(seen[pos][prev][tight][started]){
        return dp[pos][prev][tight][started];
    }

    seen[pos][prev][tight][started] = true;

    ll ans = 0;

    for(ll d = 0 ; d <= (tight ? digits[pos] : 9) ; ++d){
        bool newtight = tight && (d == (tight ? digits[pos] : 9));
        bool newstarted = started || (d!=0);

        if(!newstarted){
            ans+=dfs(pos+1,10,newtight,false);
        }
        else{
            if(started && d==prev)continue;
            ans+=dfs(pos+1,d,newtight,true);
        }
    }

    return dp[pos][prev][tight][started] = ans;
}

ll solve(ll n){
    if(n<0)return 0;
    digits.clear();

    if(n==0){
        digits.push_back(0);
    }
    else{
        while(n>0){
            digits.push_back(n%10);
            n/=10;
        }
        reverse(digits.begin(),digits.end());
    }

    memset(seen,0,sizeof(seen));
    memset(dp,0,sizeof(dp));

    return dfs(0,10,1,0);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll a,b;cin>>a>>b;
    cout << solve(b) - solve(a-1) << "\n";
}