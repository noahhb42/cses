#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0 ; i<n ; ++i)
 
int main(){
    string s;cin>>s;
    int n = s.size();
    int i = 1;
    int mx = 1;
    int cr = 1;
    char c = s[0];
    while(i<n){
        if(s[i]==c){
            cr++;
        }
        else{
            cr = 1;
            c = s[i];
        }
        mx = max(mx,cr);
        i++;
    }
    cout<<mx<<endl;
}
