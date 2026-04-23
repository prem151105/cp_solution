#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Step 1: Sort the array to use the min1 + min2 > max logic
    sort(a.begin(), a.end());

    int max_stable_elements = 0;

    // Step 2: Use two pointers to find the largest valid range [i, j]
    // where a[i] + a[i+1] > a[j]
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        // Expand j as far as possible for the current i
        while (j < n && (j < i + 2 || a[i] + a[i + 1] > a[j])) {
            max_stable_elements = max(max_stable_elements, j - i + 1);
            j++;
        }
    }

    // Step 3: Elements outside this range must be changed
    cout << n - max_stable_elements << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}