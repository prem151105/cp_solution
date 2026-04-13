#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
// here is qmax​=nm+min(n,m) q<=min(n(m+1),m(n+1)) and p=n+m+nm
    int t;
    cin >> t;
    while (t--) {
        long long p, q;
        cin >> p >> q;

        long long X = 2*p + 4*q + 1;
        bool found = false;

        for (long long i = 1; i * i <= X; i++) {
            if (X % i == 0) {
                long long a = i;
                long long b = X / i;

                // both must be odd
                if (a % 2 == 1 && b % 2 == 1) {
                    long long n = (a - 1) / 2;
                    long long m = (b - 1) / 2;

                    if (n > 0 && m > 0) {
                        long long qmax = n*m + min(n, m);

                        if (q <= qmax) {
                            cout << n << " " << m << '\n';
                            found = true;
                            break;
                        }
                    }
                }
            }
        }

        if (!found) cout << -1 << '\n';
    }

    return 0;
}