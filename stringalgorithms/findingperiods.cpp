#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define rep(i,a,n) for(int i = a ; i<n ; ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
vi z_calc(string& s){
    int n = sz(s);
    vector<int> z(n,0);
    int l = 0, r = 0;
 
    for(int i = 1 ; i<n ; ++i){
        if(i<r){
            z[i] = min(z[i-l], r-i);
        }
        while(i + z[i] < n && s[z[i]] == s[i+z[i]])z[i]++;
        if(i + z[i] > r){
            l = i;
            r = i+z[i];
        }
    }
 
    return z;
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;cin>>s;
    int n = sz(s);
    vi z = z_calc(s);
 
    rep(i,1,n)if(z[i]>=n-i)cout<<i<<" ";
    cout<<n<<"\n";
}