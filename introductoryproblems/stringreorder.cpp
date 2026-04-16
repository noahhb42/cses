#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    string s;cin>>s;
    vll nr(26,0);
    for(auto i : s){
        nr[i-'A']++;
    }
    ll rem = s.size();
    rep(i,0,26){
        if(nr[i] > (rem+1)/2){
            cout<<-1<<"\n";
            return 0;
        }
    }
    char last = '!';
    for(auto i : s){
        char first = '!';
        rep(i,0,26){
            if(nr[i]>0 && first=='!' && (char)('A'+i) != last){
                first = (char)('A'+i);
                nr[i]--;
            }
            if(nr[i]*2>rem){
                nr[first-'A']++;
                nr[i]--;
                cout<<(char)('A'+i);
                last = (char)('A'+i);
                first='!';
                break;
            }
        }
        rem--;
        if(first != '!'){
            cout<<first;
            last = first;
        }
    }
    cout<<"\n";
}