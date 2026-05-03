#include"bits/stdc++.h"
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

    int n,q;cin>>n>>q;
    vector<vi> up(n+1,vi(20,-1));
    rep(i,2,n+1){
        cin>>up[i][0];
    }

    rep(k,1,20){
        rep(i,2,n+1){
            if(up[i][k-1]!=-1)up[i][k]=up[up[i][k-1]][k-1];
        }
    }

    while(q--){
        int x,k;cin>>x>>k;
        for(int i = 19 ; i>=0 ; --i){
            if((k & (1<<i)) && x != -1)x = up[x][i];
        }
        cout << x << "\n";
    }
}