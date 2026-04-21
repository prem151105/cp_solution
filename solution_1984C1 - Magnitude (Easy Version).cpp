#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        long long pref = 0, mn = 0;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            pref += x;
            mn = min(mn, pref);
        }

        cout << pref - 2 * mn << '\n';
    }
    return 0;
}