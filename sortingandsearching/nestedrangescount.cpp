#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct Fenwick{
    int n;vector<int> bit;
    Fenwick(int n = 0): n(n), bit(n+1, 0) {}
    void reset(int m){n = m; bit.assign(n+1, 0);}
    void add(int i, int v){for(; i<=n ; i+=i&-i)bit[i]+=v;}
    int sum(int i){int s = 0;for(; i>0 ; i-=i&-i)s+=bit[i];return s;}
    int sum(int l, int r){return l>r ? 0 : sum(r)-sum(l-1);}
};

struct R{ll l,r; int id;};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    vector<R> a(n);
    vll rs;
    rep(i,0,n){
        ll l,r;cin>>l>>r;
        a[i] = {l,r,(int)i};
        rs.push_back(r);
    }
    sort(a.begin(), a.end(), [](const R& A, const R& B){
        if(A.l != B.l)return A.l < B.l;
        return A.r > B.r;
    });
    sort(rs.begin(), rs.end());
    rs.erase(unique(rs.begin(),rs.end()),rs.end());
    auto rankR = [&](ll r){return int(lower_bound(rs.begin(), rs.end(), r)-rs.begin())+1;};
    int m = rs.size();

    vll contains(n,0), contained(n,0);
    Fenwick bit(m);

    for(int i = n-1 ; i>=0 ; --i){
        int ri = rankR(a[i].r);
        contains[a[i].id] = bit.sum(ri);
        bit.add(ri,1);
    }

    bit.reset(m);
    int seen = 0;
    rep(i,0,n){
        int ri = rankR(a[i].r);
        contained[a[i].id] = seen - bit.sum(ri-1);
        bit.add(ri,1);
        seen++;
    }

    for(auto i : contains)cout<<i<<" ";cout<<"\n";
    for(auto i : contained)cout<<i<<" ";cout<<"\n";
    return 0;
}