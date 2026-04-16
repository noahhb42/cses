#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0 ; i<n ; ++i)
 
unordered_map<char,int> mp;
 
int main(){
    string s;cin>>s;
    for(auto c : s)mp[c]++;
    int o = 0;
    for(auto [x,y] : mp)if(y&1)o++;
    if(o>1){
        cout<<"NO SOLUTION\n";
        return 0;
    }
    char ans[(int)s.size()];
    int i = 0;
    for(auto [c,n] : mp){
        if(n&1){ans[(int)s.size()/2]=c;n--;}
        while(n){
            ans[i]=ans[(int)s.size()-i-1]=c;
            n-=2;
            i++;
        }
    }
    for(auto c : ans)cout<<c;
    cout<<"\n";
}