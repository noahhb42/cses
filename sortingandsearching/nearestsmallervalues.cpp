#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;
    vll a(n+1);
    rep(i,1,n+1)cin>>a[i];

    stack<array<ll,2>> st;

    rep(i,1,n+1){
        while(!st.empty() && st.top()[0] >= a[i])st.pop();
        cout << (st.empty() ? 0 : st.top()[1]) << " ";
        st.push({a[i], i});
    }

    cout << "\n";
    return 0;
}