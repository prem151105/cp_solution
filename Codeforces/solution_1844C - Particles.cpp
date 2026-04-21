#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long s = 0, p = 0;
        long long mx = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            mx = max(mx, a[i]); // for all-negative case

            if (i % 2 == 0) {
                s += max(a[i], 0LL);   // take only positives
            } else {
                p += max(a[i], 0LL);
            }
        }

        if (mx < 0) {
            cout << mx << endl;
        } else {
            cout << max(s, p) << endl;
        }
    }
    return 0;
}