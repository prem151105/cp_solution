#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> cnt(31, 0);

      
        for (int i = 0; i < n; i++) {
            for (int bit = 0; bit <= 30; bit++) {
                if (a[i] & (1 << bit)) {
                    cnt[bit]++;
                }
            }
        }

        long long ans = 0;

        for (int bit = 30; bit >= 0; bit--) {
            long long need = n - cnt[bit];

            if (need <= k) {
                k -= need;
                ans |= (1LL << bit);
            }
        }

        cout << ans << "\n";
    }
}