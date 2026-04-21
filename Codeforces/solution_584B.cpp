#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;

    long long mod = 1e9 + 7;

    long long total = power(27, n, mod);
    long long good = power(7, n, mod);

    cout << (total - good + mod) % mod << endl;
}