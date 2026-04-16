#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0 ; i<n ; ++i)
 
vector<string> graycode(int n){
    vector<string> ans;
    if(n==1){
        ans.push_back("0");
        ans.push_back("1");
        return ans;
    }
    auto ls = graycode(n-1);
    for(auto s : ls){
        ans.push_back("0"+s);
    }
    for(int i = ls.size()-1 ; i>=0 ; i--){
        ans.push_back("1"+ls[i]);
    }
    return ans;
}
 
int main(){
    int n;cin>>n;
    vector<string> sol = graycode(n);
    for(auto s : sol)cout<<s<<"\n";
}