#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long p, q;
        cin >> p >> q;

        // Key transformation
        long long S = 2LL * p + 4LL * q + 1;

        bool found = false;

        // Try to factor S into odd factors
        for (long long d = 3; d * d <= S; d += 2) {
            if (S % d == 0) {
                long long e = S / d;

                long long n = (d - 1) / 2;
                long long m = (e - 1) / 2;

                if (n > 0 && m > 0) {
                    cout << n << " " << m << "\n";
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << -1 << "\n";
        }
    }

    return 0;
}