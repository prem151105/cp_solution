#include <bits/stdc++.h>
using namespace std;

bool check(int k, vector<int>& a, int n) {
    vector<int> bit(20, 0);

    // first window
    for (int i = 0; i < k; i++) {
        for (int b = 0; b < 20; b++) {
            if (a[i] & (1 << b)) bit[b]++;
        }
    }

    int target = 0;
    for (int b = 0; b < 20; b++) {
        if (bit[b] > 0) target |= (1 << b);
    }


    for (int i = k; i < n; i++) {
        for (int b = 0; b < 20; b++) {
            if (a[i - k] & (1 << b)) bit[b]--;
            if (a[i] & (1 << b)) bit[b]++;
        }

        int cur = 0;
        for (int b = 0; b < 20; b++) {
            if (bit[b] > 0) cur |= (1 << b);
        }

        if (cur != target) return false;
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int l = 1, r = n, ans = n;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (check(mid, a, n)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << "\n";
    }
}