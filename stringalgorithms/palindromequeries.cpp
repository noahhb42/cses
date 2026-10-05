#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct FT {
	vector<H> s;
	FT(int n) : s(n) {}
	void update(int pos, H dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] = s[pos] + dif;
	}
	H query(int pos) { // sum of values in [0, pos)
		H res = 0;
		for (; pos > 0; pos &= pos - 1) res = res + s[pos-1];
		return res;
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n,q;cin>>n>>q;
    string s;cin>>s;

    vector<H> pw(n+1,0);
    pw[0] = 1;
    rep(i,1,n+1)pw[i] = pw[i-1]*C;

    FT fts(n);
    FT ftr(n);

    rep(i,0,n)fts.update(i, (H)s[i]*pw[i]),ftr.update(i, (H)s[i]*pw[n-1-i]);

    while(q--){
        int op;cin>>op;
        if(op == 1){
            int k;cin>>k;
            k--;
            char c;cin>>c;
            fts.update(k, ((H)c-(H)s[k])*pw[k]);
            ftr.update(k, ((H)c-(H)s[k])*pw[n-1-k]);
            s[k] = c;
        }
        else{
            int a,b;cin>>a>>b;
            a--;
            H f = fts.query(b) - fts.query(a);
            H r = ftr.query(b) - ftr.query(a);
            if(f * pw[n-b] == r * pw[a]){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}