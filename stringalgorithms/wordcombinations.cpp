#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define rep(i,a,n) for(int i = a ; i<n ; ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
string s;
const int mxn = 1e6+5;
const ll p = 31, mod = 1e9+7;
ll pexp[mxn], pinv[mxn];
 
ll fexp(ll a, ll b, ll mod){
    ll res = 1;
    while(b){
        if(b&1){
            res*=a;
            res%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return res;
}
 
void fill(){
    ll pi = fexp(p,mod-2,mod);
    pexp[0] = pinv[0] = 1;
    rep(i,1,mxn){
        pexp[i] = (p * pexp[i-1])%mod;
        pinv[i] = (pi * pinv[i-1])%mod;
    }
}
 
ll ctll(char c){
    return c-'a'+1;
}
 
ll hashing(string& t){
    ll h = 0;
    rep(i,0,sz(t)){
        h = (h + ctll(t[i])*pexp[i+1])%mod;
    }
    return h;
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
 
    fill();
    
    cin >> s;
    int k;cin>>k;
    unordered_map<ll, unordered_set<ll>> hashes;
    vector<ll> lens;
 
    rep(i,0,k){
        string t;cin>>t;
        int m = sz(t);
        if(!hashes.count(m))lens.push_back(m);
 
        hashes[m].insert(hashing(t));
    }
 
    sort(lens.begin(),lens.end());
 
    int n = sz(s);
    vector<ll> pref(n+1,0);
    rep(i,0,n){
        pref[i+1] = (pref[i] + ctll(s[i])*pexp[i+1])%mod;
    }
 
    vector<ll> dp(n+1,0);
    dp[n]=1;
 
    for(int i = n-1 ; i>=0 ; --i){
        for(int len : lens){
            if(i+len>n)break;
 
            ll h = (((pref[i+len]-pref[i])*pinv[i])%mod+mod)%mod;
 
            if(hashes[len].count(h)){
                dp[i] = (dp[i] + dp[i+len])%mod;
            }
        }
    }
 
    cout << dp[0] << "\n";
}