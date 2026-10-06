#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool ask(int i, int j){
    cout << "? " << i << " " << j << endl;
    string s;cin>>s;
    return s=="YES";
}

void msort(vi& v, int lo, int hi){
    if(hi-lo<2)return;
    int mid = (lo+hi)/2;
    msort(v,lo,mid);
    msort(v,mid,hi);
    vi t;
    int a = lo, b = mid;
    while(a < mid && b < hi){
        if(ask(v[a], v[b]))t.push_back(v[a++]);
        else t.push_back(v[b++]);
    }
    while(a<mid)t.push_back(v[a++]);
    while(b<mid)t.push_back(v[b++]);
    copy(all(t),v.begin()+lo);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n;cin>>n;
    vi idx(n);
    iota(all(idx),1);
    msort(idx,0,n);

    vi ans(n+1);
    rep(k,0,n)ans[idx[k]] = k+1;
    cout << "!";
    rep(i,1,n+1)cout<<" "<<ans[i];
    cout<<endl;
}