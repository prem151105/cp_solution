#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll nextCost(ll x) {
    for (int bit = 0; bit < 61; bit++) {
        if (((x >> bit) & 1) == 0) {
            return (1LL << bit);
        }
    }
    return (1LL << 60);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll k;
        cin >> n >> k;

        vector<ll> a(n);
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ans += __builtin_popcountll(a[i]);
        }

        vector<ll> costs;

        for (int i = 0; i < n; i++) {
            ll x = a[i];

            while (true) {
                ll c = nextCost(x);

                if (c > k) break;

                costs.push_back(c);
                x += c;
            }
        }

        sort(costs.begin(), costs.end());

        for (ll c : costs) {
            if (k >= c) {
                k -= c;
                ans++;
            } else {
                break;
            }
        }

        cout << ans << "\n";
    }
}