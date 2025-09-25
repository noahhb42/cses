#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll mod = 1e9+7;

ll dice(ll n){
    array<ll,36> r = {
        1,0,0,0,0,0,
        0,1,0,0,0,0,
        0,0,1,0,0,0,
        0,0,0,1,0,0,
        0,0,0,0,1,0,
        0,0,0,0,0,1
    };
    array<ll,36> m = {
        0,1,0,0,0,0,
        0,0,1,0,0,0,
        0,0,0,1,0,0,
        0,0,0,0,1,0,
        0,0,0,0,0,1,
        1,1,1,1,1,1
    };
    array<ll,36> t = {};

    auto mul = [&](const array<ll,36>& A, const array<ll,36>& B, array<ll,36>& OUT){
        fill(t.begin(), t.end(), 0);
        for(int i = 0; i < 6; ++i){
            for(int k = 0; k < 6; ++k){
                ll aik = A[i*6 + k];
                if(!aik) continue;
                for(int j = 0; j < 6; ++j){
                    t[i*6 + j] = (t[i*6 + j] + aik * B[k*6 + j]) % mod;
                }
            }
        }
        OUT = t; 
    };

    while(n){
        if(n & 1){
            mul(r, m, r);  
        }
        mul(m, m, m);       
        n >>= 1;
    }

    return (r[0]+r[1]+2*r[2]+4*r[3]+8*r[4]+16*r[5]) % mod;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    cout<<dice(n)<<endl;
}