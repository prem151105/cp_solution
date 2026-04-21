#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i]; // same as a in easy version

        if (n == 2) {
            ll g = gcd(a[0], a[1]);
            int ans = 0;
            if (g < a[0]) ans++;
            if (g < a[1]) ans++;
            cout << ans << '\n';
            continue;
        }

        vector<ll> g(n - 1);
        for (int i = 0; i < n - 1; i++) {
            g[i] = gcd(a[i], a[i + 1]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ll need;
            if (i == 0) {
                need = g[0];
            } else if (i == n - 1) {
                need = g[n - 2];
            } else {
                ll x = g[i - 1];
                ll y = g[i];
                ll z = gcd(x, y);
                need = x / z * y; // lcm(x, y)
            }

            if (need < a[i]) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}