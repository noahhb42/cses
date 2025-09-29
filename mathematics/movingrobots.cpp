#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

using Mat = array<array<long double, 64>, 64>;

Mat mul(const Mat& A, const Mat& B){
    Mat C{};
    rep(i,0,64){
        rep(k,0,64){
            long double aik = A[i][k];
            if(aik==0)continue;
            rep(j,0,64){
                C[i][j] += aik * B[k][j];
            }
        }
    }
    return C;
}

Mat mpow(Mat& A, ll e){
    Mat res{};
    rep(i,0,64)res[i][i]=1;
    while(e){
        if(e&1)res = mul(res, A);
        A = mul(A,A);
        e>>=1;
    }
    return res;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll k;cin>>k;
    
    Mat T{};
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    for(int r = 0 ; r<8 ; ++r){
        for(int c = 0 ; c<8 ; ++c){
            int u = 8*r+c;
            vector<int> nb{};
            for(int d = 0 ; d<4 ; ++d){
                int nr = r+dr[d], nc = c+dc[d];
                if(0<=nr && nr<8 && nc>=0 && nc<8)nb.push_back(8*nr+nc);
            }
            long double p = 1.0 / nb.size();
            for(int v : nb)T[u][v]=p;
        }
    }

    Mat Tk = mpow(T,k);

    long double ans = 0;
    for(int t = 0 ; t<64 ; ++t){
        long double prod = 1;
        for(int s = 0; s<64 ; ++s){
            prod*=(1-Tk[s][t]);
        }
        ans+=prod;
    }
    cout.precision(6);
    cout<<fixed<<ans<<"\n";
}
