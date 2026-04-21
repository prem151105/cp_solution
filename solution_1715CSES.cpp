#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 5;
const ll mod = 1e9 + 7;

ll fact[MAXN], invfact[MAXN];

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }

    invfact[MAXN - 1] = power(fact[MAXN - 1], mod - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    ll ans = fact[s.length()];

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            ans = ans * invfact[freq[i]] % mod;
        }
    }

    cout << ans << '\n';
}