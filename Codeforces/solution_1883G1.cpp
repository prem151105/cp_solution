#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<ll> a(n);
        a[0] = 1;
        for (int i = 1; i < n; i++) {
            cin >> a[i];
        }

        vector<ll> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0;
        int matches = 0;

        while (i < n && j < n) {
            if (b[j] > a[i]) {
                matches++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        int operations = n - matches;
        cout << operations << "\n";
    }

    return 0;
}