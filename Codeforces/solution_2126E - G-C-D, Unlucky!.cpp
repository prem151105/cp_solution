#include <bits/stdc++.h>
using namespace std;

long long lcmll(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> p(n), s(n), a(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        for (int i = 0; i < n; i++) cin >> s[i];

        for (int i = 0; i < n; i++) {
            a[i] = lcmll(p[i], s[i]);
        }

        vector<long long> pref(n), suf(n);

        pref[0] = a[0];
        for (int i = 1; i < n; i++) {
            pref[i] = gcd(pref[i - 1], a[i]);
        }

        suf[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = gcd(suf[i + 1], a[i]);
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (pref[i] != p[i] || suf[i] != s[i]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}