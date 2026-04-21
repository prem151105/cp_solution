#include <iostream>
#include <vector>
#include <numeric> // for std::gcd
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> bit_counts(30, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int bit = 0; bit < 30; bit++) {
            if ((a[i] >> bit) & 1) {
                bit_counts[bit]++;
            }
        }
    }

   
    int overall_gcd = 0;
    for (int count : bit_counts) {
        if (count > 0) {
            overall_gcd = std::gcd(overall_gcd, count);
        }
    }

    // If all numbers were 0, overall_gcd remains 0.
    // The problem says k can be any 1 <= k <= n in that case.
    if (overall_gcd == 0) {
        for (int k = 1; k <= n; k++) {
            cout << k << (k == n ? "" : " ");
        }
    } else {
        // Any divisor of the overall_gcd is a valid k
        for (int k = 1; k <= n; k++) {
            if (overall_gcd % k == 0) {
                cout << k << " ";
            }
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}