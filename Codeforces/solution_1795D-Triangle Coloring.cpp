#include <iostream>
#include <vector>
#include <algorithm>

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
    return (((fact[n] * modInverse(fact[r])) % 998244353) * modInverse(fact[n - r])) % 998244353;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int num_triangles = n / 3;
    long long ways_per_triangle = 1;
    long long MOD = 998244353;

    for (int i = 0; i < num_triangles; ++i) {
        vector<int> w(3);
        for (int j = 0; j < 3; ++j) cin >> w[j];
        sort(w.begin(), w.end());

        // Count how many ways to pick the two largest edges
        // This is equivalent to counting how many times the minimum value appears
        if (w[0] == w[1] && w[1] == w[2]) {
            ways_per_triangle = (ways_per_triangle * 3) % MOD;
        } else if (w[0] == w[1]) {
            ways_per_triangle = (ways_per_triangle * 2) % MOD;
        } else {
            ways_per_triangle = (ways_per_triangle * 1) % MOD;
        }
    }

    // Precompute factorials for nCr(num_triangles, num_triangles / 2)
    vector<long long> fact(num_triangles + 1);
    fact[0] = 1;
    for (int i = 1; i <= num_triangles; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    long long combinations = nCr(num_triangles, num_triangles / 2, fact);
    long long ans = (ways_per_triangle * combinations) % MOD;

    cout << ans << endl;

    return 0;
}