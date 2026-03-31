#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 998244353;
const int N = 200005;

ll fact[N];

// fast exponentiation
ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// modular inverse
ll inv(ll x) {
    return power(x, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // precompute factorials
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int mx = *max_element(a.begin(), a.end());

        int cnt = 0, k = 0;
        for (int x : a) {
            if (x == mx) cnt++;
            if (x == mx - 1) k++;
        }

        if (cnt >= 2) {
            cout << fact[n] << "\n";
        }
        else {
            if (k == 0) {
                cout << 0 << "\n";
            } else {
                ll ans = fact[n];
                ans = ans * k % MOD;
                ans = ans * inv(k + 1) % MOD;
                cout << ans << "\n";
            }
        }
    }

    return 0;
}