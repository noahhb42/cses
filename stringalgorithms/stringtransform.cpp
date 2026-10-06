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
    
    string s;cin>>s;
    int n = sz(s);
    
    vi nxt(n);
    iota(all(nxt),0);
    stable_sort(all(nxt), [&](int a, int b){return s[a] < s[b];});

    string ans;
    int p = nxt[0];
    rep(i,0,n-1){
        p=nxt[p];
        ans.push_back(s[p]);
    }
    cout<<ans<<"\n";
}