#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static inline ll ceil_div(ll x, ll d) {
    return (x + d - 1) / d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        ll d;
        cin >> n >> m >> d;

        vector<ll> s(m + 2);
        s[0] = 1;
        for (int i = 1; i <= m; i++) cin >> s[i];
        s[m + 1] = (ll)n + 1;

        ll total = 0;
        for (int i = 0; i <= m; i++) {
            total += ceil_div(s[i + 1] - s[i], d);
        }

        ll bestDec = -1;
        ll ways = 0;

        for (int i = 1; i <= m; i++) {
            ll dec = ceil_div(s[i] - s[i - 1], d)
                   + ceil_div(s[i + 1] - s[i], d)
                   - ceil_div(s[i + 1] - s[i - 1], d);

            if (dec > bestDec) {
                bestDec = dec;
                ways = 1;
            } else if (dec == bestDec) {
                ways++;
            }
        }

        cout << total - bestDec << ' ' << ways << '\n';
    }

    return 0;
}