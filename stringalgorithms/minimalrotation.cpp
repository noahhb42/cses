#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define rep(i,a,n) for(int i = a ; i<n ; ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;cin>>s;
    int n = sz(s);
 
    string t = s+s;
    int i = 0, j = 1, k = 0;
 
    while(i<n && j<n && k<n){
        if(t[i+k] == t[j+k])k++;
        else if(t[i+k] > t[j+k]){
            i = i+k+1;
            if(i==j)i++;
            k=0;
        }
        else{
            j = j+k+1;
            if(i==j)j++;
            k=0;
        }
    }
 
    int ind = min(i,j);
 
    rep(ii,0,n)cout<<t[ind+ii];
    cout<<"\n";
}