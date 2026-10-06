#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool ask(int i, char c, int n){
    cout << "? " << (i-1)%n + 1 << endl;
    char x;cin>>x;
    return x==c;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n;cin>>n;
    int l = 1, r = n+1;
    cout << "? " << 1 << endl;
    char c;cin>>c;

    while(r - l > 3){
        int mid = (l+r)/2;
        if((mid-l)%2==1)mid++;
        if(ask(mid,c,n)){
            r++;
            l = mid;
        }
        else{
            r = mid;
        }
    }

    if(ask(l+1,c,n)){
        cout << "! " << (l-1)%n + 1 << endl;
    }
    else{
        cout << "! " << l%n + 1 << endl;
    }
}