#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,x;cin>>n>>x;
    map<int,vector<int>> m{};
    vector<int> a(n);
    rep(i,0,n){
        cin>>a[i];
        m[a[i]].push_back(i+1);
    }
    sort(a.begin(),a.end());
    for(auto i : a){
        auto p = lower_bound(a.begin(), a.end(), x-i);
        if(p == a.end())continue;
        if(i + *p == x){
            if(i == *p && m[i].size()<2)continue;
            if(i==*p){
                cout<<m[i][0]<<" "<<m[i][1]<<"\n";
            }
            else{
                cout<<m[i][0]<<" "<<m[*p][0]<<"\n";
            }
            return 0;
        }
    }
    cout<<"IMPOSSIBLE\n";
}