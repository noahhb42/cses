#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	string s;cin>>s;
	auto m = manacher(s);
	
	vi ans(sz(s),1);
	rep(i,0,sz(s)){
	    int even = m[0][i], odd = m[1][i];
	    if(even)ans[i + even - 1] = max(ans[i + even - 1], 2*even);
	    ans[i + odd] = max(ans[i + odd], 2*odd+1);
	}
	for(int i = sz(s)-2 ; i>=0 ; --i)ans[i] = max(ans[i], ans[i+1]-2);
	for(auto i : ans)cout<<i<<" ";
	cout<<"\n";
}