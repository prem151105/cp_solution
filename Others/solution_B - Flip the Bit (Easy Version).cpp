#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int p;
        cin >> p;
        p--;   // 0-based

        int x = a[p];

        int L = 0, R = 0;

        // count wrong segments on the left
        for (int i = 0; i < p; ) {
            if (a[i] != x) {
                L++;
                while (i < p && a[i] != x) i++;
            } else {
                i++;
            }
        }

        // count wrong segments on the right
        for (int i = p + 1; i < n; ) {
            if (a[i] != x) {
                R++;
                while (i < n && a[i] != x) i++;
            } else {
                i++;
            }
        }

        cout << 2 * max(L, R) << "\n";
    }
}