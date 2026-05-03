#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int lift(int x, int k, vector<vi>& up){
    for(int i = 19 ; i>=0 ; --i){
        if(k & (1<<i))x = up[x][i];
    }
    return x;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n,q;cin>>n>>q;
    vector<vi> up(n+1,vi(20,-1));
    vector<vi> children(n+1,vi(0));
    rep(i,2,n+1){
        cin>>up[i][0];
        children[up[i][0]].push_back(i);
    }

    rep(k,1,20){
        rep(i,2,n+1){
            if(up[i][k-1]!=-1)up[i][k]=up[up[i][k-1]][k-1];
        }
    }

    vi depth(n+1,0);
    queue<int> qu;
    qu.push(1);
    while(!qu.empty()){
        int u = qu.front();qu.pop();
        for(int child : children[u]){
            depth[child] = depth[u] + 1;
            qu.push(child);
        }
    }

    while(q--){
        int a,b;cin>>a>>b;
        if(depth[a] < depth[b])swap(a,b);
        a = lift(a, depth[a]-depth[b], up);
        for(int k = 19 ; k>=0 ; --k){
            if(up[a][k] != up[b][k]){
                a = up[a][k];
                b = up[b][k];
            }
        }
        if(a == b){
            cout << a << "\n";
        }
        else cout << up[a][0] << "\n";
    }
}