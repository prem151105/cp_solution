#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
const int N = 200005;

ll fact[N], invFact[N];

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

// precompute factorials and inverse factorials
void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[N - 1] = power(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

// nCr
ll ncr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (auto &e : a) cin >> e;

        sort(a.begin(), a.end());

        vector<int> cnt(n + 1);
        for (auto e : a) cnt[e]++;

        for (int i = n; i >= 0; i--) {
            if (cnt[i] >= k) {
                cout << ncr(cnt[i], k) << "\n";
                break;
            } else {
                k -= cnt[i];
            }
        }
    }

    return 0;
}