#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n;cin>>n;
    vi sa(n);
    rep(i,0,n)cin>>sa[i],sa[i]--;
    vi rank(n+1,-1);
    rep(i,0,n)rank[sa[i]]=i;

    vector<char> ans(n,' ');
    ans[sa[0]] = 'a';
    char cur = 'a';
    rep(i,1,n){
        if(rank[sa[i]+1]<rank[sa[i-1]+1]){
            cur++;
            if(cur > 'z'){
                cout << -1 << "\n";
                return 0;
            }
        }
        ans[sa[i]] = cur;
    }
    
    for(auto c : ans)cout<<c;
    cout << "\n";
}