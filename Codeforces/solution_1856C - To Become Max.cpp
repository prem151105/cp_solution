#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long ans = *max_element(a.begin(), a.end());

        for (int i = 0; i < n; i++) {
            long long cur = a[i];
            long long ops = 0;

            for (int j = i + 1; j < n; j++) {
                if (a[j] >= cur) {
                    cur++;
                } else {
                    long long need = cur - a[j];
                    if (ops + need > k) break;
                    ops += need;
                    cur = a[j] + need;
                    cur++; // after matching, increase
                }

                if (ops > k) break;
                ans = max(ans, cur);
            }
        }

        cout << ans << '\n';
    }
}