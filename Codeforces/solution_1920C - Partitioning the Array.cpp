#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            int g = 0;

            for (int j = k; j < n; j++) {
                g = gcd(g, abs(a[j] - a[j - k]));
            }

            // FIX HERE
            if (g == 0 || g >= 2) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}