#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    int l = 0, r = 1e9;
    while(r - l > 1){
        int mid = (r+l)/2;
        cout << "? " << mid << endl;
        cout.flush();
        string s;cin>>s;
        if(s=="YES")l = mid;
        else r=mid;
    }
    cout << "! " << r << endl;
    cout.flush();
}