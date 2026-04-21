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

        vector<long long> x(n), y(n);

        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        long long ans;

        if (n % 2 == 1) {
            // odd → only one median
            ans = 1;
        } else {
            // even → range of medians
            long long dx = x[n/2] - x[n/2 - 1] + 1;
            long long dy = y[n/2] - y[n/2 - 1] + 1;
            ans = dx * dy;
        }

        cout << ans << "\n";
    }

    return 0;
}