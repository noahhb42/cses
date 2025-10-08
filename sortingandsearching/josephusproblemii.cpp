#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct Fenwick{
    vector<int> bit;
    int n;
    Fenwick(int n): n(n), bit(n+1, 0) {}
    void add(int idx, int val){
        for( ; idx<=n ; idx += idx & -idx)bit[idx]+=val;
    }
    int sum(int idx){
        int s = 0;
        for(; idx>0 ; idx -= idx & -idx)s+=bit[idx];
        return s;
    }
    int findKth(int k){
        int idx = 0, mask = 1<<18;
        while(mask){
            int next = idx + mask;
            if(next <= n && bit[next]<k){
                k -= bit[next];
                idx = next;
            }
            mask >>= 1;
        }
        return idx + 1;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n,k;cin>>n>>k;

    Fenwick ft(n);
    rep(i,1,n+1)ft.add(i, 1);

    int alive = n;
    ll cur = 1;
    rep(_,0,n){
        cur = (cur + k) % alive;
        if(cur==0)cur=alive;
        int idx = ft.findKth(cur);
        cout<<idx<<" ";
        ft.add(idx,-1);
        alive--;
    }
    cout<<"\n";
    return 0;
}
