#include"bits/stdc++.h"
using namespace std;
 
int main(){
    string s;cin>>s;
    sort(s.begin(),s.end());
    string ans[1<<(2*(int)s.size())]; size_t i = 0;
    do{
        ans[i] = s;
        i++;
    } while (next_permutation(s.begin(),s.end()));
    cout << (int)i << "\n";
    for(size_t j = 0 ; j<i ; ++j)cout << ans[j] << "\n";
}
