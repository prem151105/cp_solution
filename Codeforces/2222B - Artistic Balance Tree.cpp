#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        vector<long long> s1, s2;

        // 1-based indexing:
        // s1 = odd positions
        // s2 = even positions
        for (int i = 0; i < n; i++) {
            if ((i + 1) % 2 == 1) {
                s1.push_back(a[i]);
            } else {
                s2.push_back(a[i]);
            }
        }

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int c1 = 0, c2 = 0;
        int p1 = 0, p2 = 0;

        // count parity occurrences from b
        for (int i = 0; i < m; i++) {
            if (b[i] % 2 == 1) {
                c1++; // odd index marks odd-position elements
            } else {
                c2++; // even index marks even-position elements
            }
        }

        // count positive in s1
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] > 0) p1++;
        }

        // count positive in s2
        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] > 0) p2++;
        }

        long long ans1 = 0;

        // IMPORTANT EDGE CASE:
        // if no operation for odd parity, keep everything
        if (c1 == 0) {
            for (int i = 0; i < s1.size(); i++) {
                ans1 += s1[i];
            }
        }
        // if all are <= 0, must mark exactly one largest element
        else if (p1 == 0) {
            for (int i = 0; i < (int)s1.size() - 1; i++) {
                ans1 += s1[i];
            }
        }
        // if positive count <= available marks, remove all positives
        else if (p1 <= c1) {
            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] <= 0) ans1 += s1[i];
            }
        }
        // remove only largest c1 positives
        else {
            for (int i = 0; i < (int)s1.size() - c1; i++) {
                ans1 += s1[i];
            }
        }

        long long ans2 = 0;

        // IMPORTANT EDGE CASE:
        // if no operation for even parity, keep everything
        if (c2 == 0) {
            for (int i = 0; i < s2.size(); i++) {
                ans2 += s2[i];
            }
        }
        // if all are <= 0, must mark exactly one largest element
        else if (p2 == 0) {
            for (int i = 0; i < (int)s2.size() - 1; i++) {
                ans2 += s2[i];
            }
        }
        else if (p2 <= c2) {
            for (int i = 0; i < s2.size(); i++) {
                if (s2[i] <= 0) ans2 += s2[i];
            }
        }
        else {
            for (int i = 0; i < (int)s2.size() - c2; i++) {
                ans2 += s2[i];
            }
        }

        cout << ans1 + ans2 << "\n";
    }

    return 0;
}