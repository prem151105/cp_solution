#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int c = 0; // count of '+'
    for (char ch : s) {
        if (ch == '+') c++;
    }

    int q;
    cin >> q;

    while (q--) {
        long long a, b;
        cin >> a >> b;

        if (a == b) {
            // need n = 2*c
            if (n == 2 * c) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }

        long long num = b * (n - 2LL * c);
        long long den = a - b;

        // must be integer
        if (num % den != 0) {
            cout << "NO\n";
            continue;
        }

        long long d = num / den;

        // check feasibility of x2
        // x2 ∈ [0, n-c] and x2 ∈ [-d, c-d]
        long long L = max(0LL, -d);
        long long R = min((long long)(n - c), (long long)(c - d));

        if (L <= R) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}