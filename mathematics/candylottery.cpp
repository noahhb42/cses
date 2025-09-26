#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

ll round_half_even_6(long double x) {

    long double S = 1'000'000.0L;
    long double y = x * S;
    long double f = floorl(y);
    long double frac = y - f;

    const long double EPS = 1e-13L;
    if (fabsl(frac - 0.5L) <= EPS) {
        if (fmodl(f, 2.0L) != 0.0L) f += 1.0L;
    } else if (frac > 0.5L) {
        f += 1.0L;
    }
    return (long long)f;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, k;
    cin>>n>>k;

    long double ans = 0.0;
    for (int m = 1; m <= k; ++m) {
        long double x = (long double)(m - 1) / (long double)k;
        ans += 1.0L - powl(x, (long double)n);
    }

    long long q = round_half_even_6(ans);
    long long ip = q / 1'000'000;
    long long fp = q % 1'000'000;

    cout << ip << '.' << setw(6) << setfill('0') << fp << '\n';
    return 0;
}
