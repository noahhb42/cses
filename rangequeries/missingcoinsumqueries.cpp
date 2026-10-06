#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int depth = 31 - __builtin_clz(b - a);
		return min(jmp[depth][a], jmp[depth][b - (1 << depth)]);
	}
};

const int B = 30; // bucket b holds values in [2^b, 2^(b+1))

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n,q;cin>>n>>q;

    // cnt[i][b] = number of bucket b values among the first i
    vector<array<int,B>> cnt(n+1);
    vector<vi> val(B);
    vector<vector<ll>> pre(B, vector<ll>(1,0));
    rep(i,0,n){
        int x;cin>>x;
        int b = 31 - __builtin_clz(x);
        cnt[i+1] = cnt[i];
        cnt[i+1][b]++;
        val[b].push_back(x);
        pre[b].push_back(pre[b].back() + x);
    }

    vector<RMQ<int>> rmq;
    rep(b,0,B)rmq.emplace_back(val[b]);

    while(q--){
        int l,r;cin>>l>>r;l--;
        ll cur = 0; // every sum in [0, cur] can be made
        rep(b,0,B){
            int lo = cnt[l][b], hi = cnt[r][b];
            if(lo == hi)continue;
            if(rmq[b].query(lo,hi) > cur+1)break;
            // smallest fits, so cur >= 2^(b+1)-1 after it and the rest fit too
            cur += pre[b][hi] - pre[b][lo];
        }
        cout << cur+1 << "\n";
    }
}
