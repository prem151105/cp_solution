#include <iostream>
 
using namespace std;
 
// Standard Modular Exponentiation function
// Calculates (base^exp) % mod in O(log exp) time
long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 1e9 + 7;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
 
int main() {
    long long n, m;
    if (!(cin >> n >> m)) return 0;
 
    long long mod = 1e9 + 7;
 
    // Step 1: Calculate (2^m - 1)
    // We subtract 1 because at least one box must contain a present of a specific kind.
    long long combinations_per_kind = (power(2, m) - 1 + mod) % mod;
 
    // Step 2: Calculate (combinations_per_kind)^n
    // Since each of the n kinds is independent.
    long long total_ways = power(combinations_per_kind, n);
 
    cout << total_ways << endl;
 
    return 0;
}