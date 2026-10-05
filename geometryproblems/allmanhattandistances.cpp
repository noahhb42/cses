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
	
	ll n;cin>>n;
	vector<ll> x(n),y(n);
	rep(i,0,n)cin>>x[i]>>y[i];
	sort(all(x));sort(all(y));
	ll fac = -n+1;
	__int128 sm = 0;
	rep(i,0,n){
	    sm += fac*(x[i]+y[i]);
	    fac += 2;
	}
	if(sm == (__int128)0){
	    cout<<0<<"\n";
	    return 0;
	}
	vector<ll> ans;
	while(sm){
	    ans.push_back((ll)(sm%10));
	    sm/=10;
	}
	reverse(all(ans));
	for(auto i : ans)cout<<i;cout<<"\n";
}