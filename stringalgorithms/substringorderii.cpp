#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string s, int lim=256) { // or vector<int>
		s.push_back(0); int n = sz(s), k = 0, a, b;
		vi x(all(s)), y(n), ws(max(n, lim));
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		for (int i = 0, j; i < n - 1; lcp[x[i++]] = k)
			for (k && k--, j = sa[x[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    string s;cin>>s;
    int n = sz(s);
    ll k;cin>>k;

    SuffixArray sa(s);

    vector<ll> pre(n+2, 0);
    rep(i,0,n+1)pre[i+1] = pre[i] + (n - sa.sa[i]);

    int lo = 1, hi = n+1, d = 0;
    string ans;

    auto count = [&](int a, int b) -> ll {
        return pre[b] - pre[a] - (ll)d*(b-a);
    };

    auto chr = [&](int i) -> char {
        return sa.sa[i] + d < n ? s[sa.sa[i] + d] : 0;
    };

    auto lower = [&](int x, int y, int c) -> int {
        while(x < y){
            int m = (x+y)/2;
            if(chr(m) >= c)y = m;
            else x = m+1;
        }
        return x;
    };

    while(true){
        if(d > 0){
            if(k <= hi-lo)break;
            k -= hi-lo;
        }

        for(char c = 'a'; c <= 'z'; c++){
            int a = lower(lo, hi, c), b = lower(a, hi, c+1);

            ll cnt = count(a,b);

            if(cnt >= k){
                lo = a, hi = b;
                d ++;
                ans.push_back(c);
                break;
            }
            else k-=cnt;
        }
    }

    cout << ans << "\n";
}
