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

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> mn(n), mx(n);

        for (int i = 0; i < n; i++) {
            int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            mn[i] = b[pos] - a[i];
        }

        int j = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            mx[i] = b[j] - a[i];

            if (i > 0 && a[i] > b[i - 1]) {
                j = i - 1;
            }
        }

        for (int x : mn) cout << x << " ";
        cout << "\n";

        for (int x : mx) cout << x << " ";
        cout << "\n";
    }
}