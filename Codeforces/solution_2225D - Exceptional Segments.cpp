#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;

        ll zL = (x + 4) / 4;
        ll zT = (n + 5) / 4;
        ll oL = (x + 2) / 4;
        ll oT = (n + 3) / 4;

        ll zR = zT - zL;
        ll oR = oT - oL;

        ll ans = (zL % MOD) * (zR % MOD) % MOD;
        ans = (ans + (oL % MOD) * (oR % MOD) % MOD) % MOD;

        cout << ans << '\n';
    }
    return 0;
}