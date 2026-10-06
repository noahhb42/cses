#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct AhoCorasick {
	enum {alpha = 26, first = 'a'}; // change this!
	struct Node {
		// (nmatches is optional)
		int back, next[alpha], start = -1, end = -1, nmatches = 0;
		Node(int v) { memset(next, v, sizeof(next)); }
	};
	vector<Node> N;
	vi backp;
	void insert(string& s, int j) {
		assert(!s.empty());
		int n = 0;
		for (char c : s) {
			int& m = N[n].next[c - first];
			if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
			else n = m;
		}
		if (N[n].end == -1) N[n].start = j;
		backp.push_back(N[n].end);
		N[n].end = j;
		N[n].nmatches++;
	}
	AhoCorasick(vector<string>& pat) : N(1, -1) {
		rep(i,0,sz(pat)) insert(pat[i], i);
		N[0].back = sz(N);
		N.emplace_back(0);

		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = N[n].back;
			rep(i,0,alpha) {
				int &ed = N[n].next[i], y = N[prev].next[i];
				if (ed == -1) ed = y;
				else {
					N[ed].back = y;
					(N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
						= N[y].end;
					N[ed].nmatches += N[y].nmatches;
					q.push(ed);
				}
			}
		}
	}
	vi find(string word) {
		int n = 0;
		vi res; // ll count = 0;
		for (char c : word) {
			n = N[n].next[c - first];
			res.push_back(N[n].end);
			// count += N[n].nmatches;
		}
		return res;
	}
	vector<vi> findAll(vector<string>& pat, string word) {
		vi r = find(word);
		vector<vi> res(sz(word));
		rep(i,0,sz(word)) {
			int ind = r[i];
			while (ind != -1) {
				res[i - sz(pat[ind]) + 1].push_back(ind);
				ind = backp[ind];
			}
		}
		return res;
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    string word;cin>>word;
    int n;cin>>n;
    vector<string> pat(n);
    for(auto &s : pat)cin>>s;

    AhoCorasick aho(pat);
    auto occur = aho.find(word);
    
    vi first(n, INT_MAX);

    rep(i,0,sz(word)){
        if(occur[i] != -1){
            first[occur[i]] = min(first[occur[i]], i);
        }
    }

    vi ord(n);
    iota(all(ord),0);
    sort(all(ord), [&](int a, int b){
        if(sz(pat[a]) != sz(pat[b])) return sz(pat[a]) > sz(pat[b]);
        return a > b;
    });

    for(auto i : ord)if(aho.backp[i] != -1)first[aho.backp[i]] = min(first[aho.backp[i]], first[i]);

    rep(i,0,n){
        if(first[i] == INT_MAX){
            cout << "-1\n";
        }
        else{
            cout << first[i] - sz(pat[i]) + 2 << "\n";
        }
    }
}