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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        // Duplicate values => impossible
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        // Check every modulus from 2 to n/2
        for (int m = 2; m <= n / 2 && ok; m++) {
            vector<int> cnt(m, 0);
            for (int i = 0; i < n; i++) {
                cnt[a[i] % m]++;
            }

            int mn = *min_element(cnt.begin(), cnt.end());
            if (mn >= 2) ok = false;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}