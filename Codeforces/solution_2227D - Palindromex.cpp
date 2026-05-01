#include <bits/stdc++.h>
using namespace std;

int mex(const set<int>& st) {
    int m = 0;
    for (auto x : st) {
        if (x != m) return m;
        m++;
    }
    return m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) cin >> a[i];

        vector<int> ind;
        for (int i = 0; i < 2 * n; i++) {
            if (a[i] == 0) ind.push_back(i);
        }

        int L = ind[0], R = ind[1];

        set<int> ans, ans2, ans3;

        // include 0 in main ans
        ans.insert(0);

        // CASE 1: palindrome between two zeros
        int l = L, r = R;
        bool ok = true;

        while (l < r) {
            if (a[l] != a[r]) {
                ok = false;
                break;
            }
            ans.insert(a[l]);
            l++;
            r--;
        }

        // handle middle element
        if (ok && l == r) {
            ans.insert(a[l]);
        }

        // expand outward ONLY if inner is palindrome
        if (ok) {
            int p = L - 1, q = R + 1;
            while (p >= 0 && q < 2 * n && a[p] == a[q]) {
                ans.insert(a[p]);
                p--;
                q++;
            }
        }

        // CASE 2: expand around first zero
        ans2.insert(0);
        int p1 = L - 1, q1 = L + 1;
        while (p1 >= 0 && q1 < 2 * n && a[p1] == a[q1]) {
            ans2.insert(a[p1]);
            p1--;
            q1++;
        }

        // CASE 3: expand around second zero
        ans3.insert(0);
        int p2 = R - 1, q2 = R + 1;
        while (p2 >= 0 && q2 < 2 * n && a[p2] == a[q2]) {
            ans3.insert(a[p2]);
            p2--;
            q2++;
        }

        int res = 0;

        // only use ans if valid
        if (ok) res = max(res, mex(ans));

        res = max(res, mex(ans2));
        res = max(res, mex(ans3));

        cout << res << '\n';
    }
}
