#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int spf[N + 1];

void sieve() {
    for (int i = 2; i <= N; i++) spf[i] = i;
    for (int i = 2; 1LL * i * i <= N; i++) {
        if (spf[i] != i) continue;
        for (int j = i * i; j <= N; j += i) {
            if (spf[j] == j) spf[j] = i;
        }
    }
}

// returns:
// -1 → multiple primes
// p  → prime power base
// 1  → if x == 1
int primebase(int x) {
    if (x == 1) return 1;

    int p = spf[x];
    while (x % p == 0) x /= p;

    if (x > 1) return -1; // another prime exists
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (is_sorted(a.begin(), a.end())) {
            cout << "Bob\n";
            continue;
        }

        bool has_bad = false;

        for (int i = 0; i < n; i++) {
            b[i] = primebase(a[i]);
            if (b[i] == -1) {
                has_bad = true;
            }
        }

        if (has_bad) {
            cout << "Alice\n";
            continue;
        }

        if (is_sorted(b.begin(), b.end())) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
}