#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
long long power(long long base, long long exp) {
    long long res = 1;
    base %= 1000000007;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 1000000007;
        base = (base * base) % 1000000007;
        exp /= 2;
    }
    return res;
}
 
long long modInverse(long long n) {
    return power(n, 1000000007 - 2);
}
 
long long fact[200005];
long long invFact[200005];
 
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fact[i] = (fact[i - 1] * i) % 1000000007;
        invFact[i] = modInverse(fact[i]);
    }
}
 
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % 1000000007) * invFact[n - r]) % 1000000007;
}
 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    long long ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        // Move j to the furthest index where a[j] - a[i] <= k
        while (j < n && a[j] - a[i] <= k) {
            j++;
        }
        // Number of elements in range (i, j-1] is (j-1) - i
        // We choose m-1 more elements from these j-i-1 elements
        ans = (ans + nCr(j - i - 1, m - 1)) % 1000000007;
    }
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}