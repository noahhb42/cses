#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> Mat;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mod = 1'000'000'007;


Mat mul(const Mat& A, const Mat& B) {
    int n = (int)A.size();
    Mat C(n, vector<ll>(n, 0));
    rep(i,0,n) {
        rep(k,0,n) {
            ll aik = A[i][k];
            if (!aik) continue;
            rep(j,0,n) {
                if (!B[k][j]) continue;
                C[i][j] = (C[i][j] + aik * B[k][j]) % mod;
            }
        }
    }
    return C;
}

Mat mat_pow(Mat base, ll e) {
    ll n = (ll)base.size();
    Mat res(n, vector<ll>(n, 0));
    rep(i,0,n)res[i][i] = 1;

    while(e){
        if (e & 1) res = mul(res, base);
        base = mul(base, base);
        e >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n,m,k;cin>>n>>m>>k;

    Mat A(n, vll(n, 0));
    rep(i,0,m){
        ll a,b;cin>>a>>b;a--;b--;
        A[a][b]++;
    }

    Mat Ak = mat_pow(A, k);
    cout << Ak[0][n-1] % mod << '\n';
}
