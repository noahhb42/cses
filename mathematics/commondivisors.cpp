#include "bits/stdc++.h"
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    vector<int> cnt(mx + 1, 0);
    for (int x : a) ++cnt[x];

    for (int g = mx; g >= 1; --g) {
        int c = 0;
        for (int m = g; m <= mx; m += g) c += cnt[m];
        if (c >= 2) {
            cout << g << '\n';
            return 0;
        }
    }
    return 0;
}
