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

        vector<int> a(n + 1), b;
        b.reserve(n);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b.push_back(a[i]);
        }

        sort(b.begin(), b.end());
        int med = b[n / 2];

        vector<int> dp(n + 1, -1e9);
        dp[0] = 0;

        for (int l = 1; l <= n; l++) {
            if (dp[l - 1] < 0) continue;

            int less = 0, greater = 0, equal = 0;

            for (int r = l; r <= n; r++) {
                if (a[r] < med) less++;
                else if (a[r] > med) greater++;
                else equal++;

                int len = r - l + 1;

                if (len % 2 == 1 && abs(greater - less) <= equal - 1) {
                    dp[r] = max(dp[r], dp[l - 1] + 1);
                }
            }
        }

        cout << dp[n] << '\n';
    }

    return 0;
}