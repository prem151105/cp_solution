#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        long long s = 0;

        for (int i = 0; i < n; i++) {
            int low = l - a[i];
            int high = r - a[i];

            auto left = lower_bound(a.begin() + i + 1, a.end(), low);
            auto right = upper_bound(a.begin() + i + 1, a.end(), high);

            s += (right - left);
        }

        cout << s << endl;
    }
}