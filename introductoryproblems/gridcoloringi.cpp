#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    ll n, m;cin>>n>>m;
    vector<string> inp;
    rep(i,0,n){
        string s;cin>>s;
        inp.push_back(s);
    }
    rep(i,0,n){
        rep(j,0,m){
            if((i+j)&1){
                if(inp[i][j]=='A')cout<<'B';
                else cout<<'A';
            }
            else{
                if(inp[i][j]=='C')cout<<'D';
                else cout<<'C';
            }
        }
        cout<<"\n";
    }
}