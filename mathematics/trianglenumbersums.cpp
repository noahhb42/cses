#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t;cin>>t;
    vll q(t);
    ll nmax = 0;
    rep(i,0,t){
        cin>>q[i];
        nmax = max(nmax, q[i]);
    }

    vll tri(0);
    for(ll k = 1, cur = 0; ;++k){
        cur+=k;
        if(cur>nmax)break;
        tri.push_back(cur);
    }

    auto isTri = [&](ll a) -> ll{
        return binary_search(tri.begin(), tri.end(), a);
    };

    auto isTwoTri = [&](ll a) -> ll{
        ll i = 0, j = tri.size()-1;
        while(i<=j){
            ll s = tri[i]+tri[j];
            if(s==a)return true;
            if(s<a)i++;
            else j--;
        }
        return false;
    };

    for(ll n : q){
        if(isTri(n))cout<<1<<"\n";
        else if(isTwoTri(n))cout<<2<<"\n";
        else cout<<3<<"\n";
    }
}