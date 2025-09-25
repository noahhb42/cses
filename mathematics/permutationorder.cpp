#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

using u128 = __uint128_t;
using ull = unsigned long long;

struct Fenwick{
    ll n;
    vll f;
    Fenwick(ll n = 0): n(n), f(n+1, 0) {}
    void add(ll i, ll delta){for(; i <=n ; i+=i&-i) f[i]+=delta;}
    ll sum(ll i){ll s = 0; for(; i>0 ; i-=i&-i) s+= f[i]; return s;}
    ll kth(ll k){
        ll idx = 0;
        ll bit = (1<<(31-__builtin_clz(n)));
        for(; bit ; bit>>=1){
            ll next = idx+bit;
            if(next <= n && f[next]<k){
                idx = next;
                k -= f[next];
            }
        }
        return idx+1;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<unsigned long long> fact(21, 1);
    for(int i = 1 ; i<=20 ; ++i)fact[i] = fact[i-1] * (unsigned long long)i;

    ll t;cin>>t;
    while(t--){
        ll type, n;
        cin>>type>>n;
        if(type==1){
            unsigned long long k; cin>>k;
            unsigned long long x = k-1;
            Fenwick bit(n);
            for(int i = 1 ; i<=n ; ++i)bit.add(i,1);

            vll ans;
            rep(i,0,n){
                unsigned long long block = fact[n-1-i];
                unsigned long long idx = (block ? x/block : 0);
                ll pos = bit.kth((ll)idx + 1);
                ans.push_back(pos);
                bit.add(pos,-1);
                x = (block ? x%block : 0);
            }
            rep(i,0,n){
                if(i)cout<<" ";
                cout<<ans[i];
            }
            cout<<"\n";
        }
        else{
            vll a(n);
            rep(i,0,n)cin>>a[i];
            Fenwick bit(n);
            for(int i = 1 ; i<=n ; ++i){
                bit.add(i,1);
            }

            unsigned long long rank = 0;
            rep(i,0,n){
                ll smaller_unused = bit.sum(a[i]-1);
                rank += (unsigned long long)smaller_unused * fact[n-1-i];
                bit.add(a[i],-1);
            }
            cout<<(rank + 1)<<"\n";
        }
    }
}


/*

O(n^2) solution



#include <bits/stdc++.h>
using namespace std;

using u128 = __uint128_t;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // factorials up to 20!
    vector<ull> fact(21, 1);
    for (int i = 1; i <= 20; ++i) fact[i] = fact[i-1] * (ull)i;

    int t; 
    if(!(cin >> t)) return 0;
    while (t--) {
        int type, n; 
        cin >> type >> n;

        if (type == 1) {
            // 1 n k  -> print p(n, k)
            unsigned long long k; 
            cin >> k;
            // build list of remaining numbers
            vector<int> rem(n);
            iota(rem.begin(), rem.end(), 1);

            // 0-based rank
            unsigned long long x = k - 1;
            vector<int> ans;
            for (int i = 0; i < n; ++i) {
                ull f = fact[n-1-i];
                ull idx = (f ? x / f : 0);
                x = (f ? x % f : 0);
                ans.push_back(rem[(size_t)idx]);
                rem.erase(rem.begin() + (ptrdiff_t)idx);
            }
            for (int i = 0; i < n; ++i) {
                if (i) cout << ' ';
                cout << ans[i];
            }
            cout << '\n';
        } else {
            // 2 n p(n,k)  -> print k
            vector<int> a(n);
            for (int i = 0; i < n; ++i) cin >> a[i];

            vector<int> used(n + 1, 0); // numbers are 1..n
            unsigned long long rank0 = 0; // 0-based
            for (int i = 0; i < n; ++i) {
                int smaller_unused = 0;
                for (int v = 1; v < a[i]; ++v)
                    if (!used[v]) ++smaller_unused;
                used[a[i]] = 1;
                rank0 += (unsigned long long)smaller_unused * fact[n-1-i];
            }
            cout << (rank0 + 1) << '\n';
        }
    }
    return 0;
}

*/