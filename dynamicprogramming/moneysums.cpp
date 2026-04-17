#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const int mxn = 100001;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;cin>>n;
    vll a(n);
    for(auto&i:a)cin>>i;

    bitset<mxn> b;
    b[0]=1;

    for(auto c : a){
        for(int i = mxn-1 ; i>=c ; --i){
            if(b[i-c])b[i]=1;
        }
    }

    int ans = 0;
    rep(i,1,mxn)if(b[i])ans++;
    cout<<ans<<endl;

    rep(i,1,mxn){
        if(b[i])cout<<i<<" ";
    }
    cout<<endl;
}