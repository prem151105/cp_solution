#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        long long m;
        cin >> n >> m;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int cur = 1;
        bool bad = false;

        auto val = [&](int i) -> long long {
            
            return (a[i] + (i + 1)) % m;
        };

        long long prev = val(0);

        for (int i = 1; i < n; i++) {
            long long now = val(i);
            if (now == (prev + 1) % m) cur++;
            else cur = 1;

            if (cur >= m) {
                bad = true;
                break;
            }
            prev = now;
        }

        cout << (bad ? "NO" : "YES") << '\n';
    }

    return 0;
}