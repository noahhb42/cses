#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    vector<array<ll,3>> a(n);
    rep(i,0,n){
        ll l,r;cin>>l>>r;
        a[i] = {l,r,i};
    }
    sort(a.begin(), a.end());

    priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
    stack<ll> free_ids;
    vll ans(n);
    ll rooms = 0;
    for(auto [x,y,id] : a){
        while(!pq.empty() && pq.top()[0]<x){
            free_ids.push(pq.top()[1]);
            pq.pop();
        }
        ll rid;
        if(!free_ids.empty()){rid = free_ids.top(); free_ids.pop();}
        else{rid = ++rooms;}
        ans[id] = rid;
        pq.push({y, rid});
    }
    cout<<rooms<<"\n";
    for(auto i : ans)cout<<i<<" ";cout<<"\n";
    return 0;
}