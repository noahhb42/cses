#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> Mat;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = (1LL<<62);

Mat minplus_mul(const Mat& A, const Mat& B) {
    ll n = (ll)A.size();
    Mat C(n, vll(n, INF));
    rep(i,0,n) {
        rep(k,0,n) {
            ll aik = A[i][k];
            if (aik == INF) continue;
            rep(j,0,n) {
                ll bkj = B[k][j];
                if(bkj == INF)continue;
                ll cand = (aik + bkj);
                C[i][j] = min(C[i][j],cand);
            }
        }
    }
    return C;
}

Mat minplus_pow(Mat base, ll e) {
    ll n = (ll)base.size();
    Mat res(n, vector<ll>(n, INF));
    rep(i,0,n)res[i][i] = 0;

    while(e){
        if (e & 1) res = minplus_mul(res, base);
        base = minplus_mul(base, base);
        e >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n,m,k;cin>>n>>m>>k;

    Mat A(n, vll(n, INF));
    rep(i,0,m){
        ll a,b,c;cin>>a>>b>>c;a--;b--;
        A[a][b]=min(A[a][b],c);
    }

    Mat Ak = minplus_pow(A, k);
    ll ans = Ak[0][n-1];
    if(ans==INF)cout<<-1<<"\n";
    else cout<<ans<<"\n";
}
