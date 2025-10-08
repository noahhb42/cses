#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin>>n>>m;
    vll a(n+1), pos(n+1);
    rep(i,1,n+1){
        ll x;cin>>x;
        a[i] = x;
        pos[x] = i;
    }
    ll rounds = 1;
    rep(i,1,n){
        if(pos[i+1]<pos[i])rounds++;
    }
    while(m--){
        int i,j;cin>>i>>j;
        if(i==j){
            cout<<rounds<<"\n";
            continue;
        }

        int va = a[i], vb = a[j];
        vector<int> idx(0);
        for(int t : {va-1, va, vb-1, vb})if(t>=1 && t<n)idx.push_back(t);
        sort(idx.begin(), idx.end());
        idx.erase(unique(idx.begin(), idx.end()), idx.end());

        for(int i : idx)if(pos[i+1]<pos[i])rounds--;

        swap(a[i],a[j]);
        pos[va]=j;
        pos[vb]=i;

        for(int i : idx)if(pos[i+1]<pos[i])rounds++;

        cout<<rounds<<"\n";
    }
}