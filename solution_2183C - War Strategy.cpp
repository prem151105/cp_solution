#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;
 
        long long a = 0;              // to the left of k
        long long b = 0;              // to the right of k
        long long L = k - 1;
        long long R = n - k;
 
        while (true) {
            bool changed = false;
 
            // Try extend to the right
            if (b < R && a + (b + 1) + max(a, b + 1) - 1 <= m) {
                ++b;
                changed = true;
            }
 
            // Try extend to the left
            if (a < L && (a + 1) + b + max(a + 1, b) - 1 <= m) {
                ++a;
                changed = true;
            }
 
            if (!changed) break;
        }
 
        cout << (a + b + 1) << '\n';
    }
    return 0;
}