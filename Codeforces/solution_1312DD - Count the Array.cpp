#include <iostream>
#include <vector>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, 998244353 - 2);
}

long long nCr(int n, int r, const vector<long long>& fact) {
    if (r < 0 || r > n) return 0;
    return fact[n] * modInverse(fact[r]) % 998244353 * modInverse(fact[n - r]) % 998244353;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }

    const int MOD = 998244353;
    vector<long long> fact(m + 1);
    fact[0] = 1;
    for (int i = 1; i <= m; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    // Formula: C(m, n-1) * (n-2) * 2^(n-3)
    long long ans = nCr(m, n - 1, fact);
    ans = (ans * (n - 2)) % MOD;
    ans = (ans * power(2, n - 3)) % MOD;

    cout << ans << endl;

    return 0;
}