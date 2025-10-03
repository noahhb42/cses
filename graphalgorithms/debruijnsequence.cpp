#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;

    if(n==1){
        cout<<"01\n";
        return 0;
    }

    ll M = 1 << (n-1);
    ll mask = M-1;
    vll it(M,0);
    string seq;

    stack<ll> st;
    st.push(0);
    while(!st.empty()){
        ll u = st.top();
        ll& i = it[u];
        if(i<2){
            ll b = i++;
            ll v = (u<<1 & mask) | b;
            st.push(v);
        }
        else{
            st.pop();
            if(!st.empty())seq.push_back(char('0'+(u&1)));
        }
    }
    reverse(seq.begin(), seq.end());
    cout<<string(n-1,'0')<<seq<<"\n";
    return 0;
}