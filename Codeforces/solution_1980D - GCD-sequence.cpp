#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool check(vector<int>& a, int removeIdx) {
    vector<int> b;

    for (int i = 0; i < (int)a.size(); i++) {
        if (i != removeIdx) b.push_back(a[i]);
    }

    vector<int> g;
    for (int i = 0; i + 1 < (int)b.size(); i++) {
        g.push_back(__gcd(b[i], b[i + 1]));
    }

    for (int i = 0; i + 1 < (int)g.size(); i++) {
        if (g[i] > g[i + 1]) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> g(n - 1);

        for (int i = 0; i < n - 1; i++) {
            g[i] = __gcd(a[i], a[i + 1]);
        }

        int bad = -1;

        for (int i = 0; i < n - 2; i++) {
            if (g[i] > g[i + 1]) {
                bad = i;
                break;
            }
        }

        if (bad == -1) {
            cout << "YES\n";
            continue;
        }

        bool ok = false;

        for (int i = max(0, bad - 1); i <= min(n - 1, bad + 2); i++) {
            if (check(a, i)) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}