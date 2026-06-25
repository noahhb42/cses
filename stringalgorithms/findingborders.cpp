#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define rep(i,a,n) for(int i = a ; i<n ; ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
string s;
 
vi prefcalc(string& s){
    int n = sz(s);
    vi pi(n,0);
    rep(i,1,n){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j])j++;
        pi[i] = j;
    }
    return pi;
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>s;
 
    vi pi = prefcalc(s);
 
    vi ans;
    int cr = pi[sz(s)-1];
    if(cr > 0){
        do{
            ans.push_back(cr);
            cr = pi[cr-1];
        } while(cr > 0);
    }
 
    reverse(all(ans));
    for(auto i : ans)cout << i << " ";
    cout<<"\n";
}