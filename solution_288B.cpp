#include <iostream>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 1000000007;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    long long MOD = 1000000007;
    long long ans = power(k, k - 1);
    ans = (ans * power(n - k, n - k)) % MOD;

    cout << ans << endl;

    return 0;
}