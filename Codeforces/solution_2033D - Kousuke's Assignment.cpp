#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        map<long long, int> last;
        vector<pair<int, int>> vp;

        long long pref = 0;
        last[0] = -1;

        for (int i = 0; i < n; i++) {
            pref += a[i];

            if (last.find(pref) != last.end()) {
                int l = last[pref] + 1;
                int r = i;
                vp.push_back({l, r});
            }

            last[pref] = i;
        }

        if (vp.empty()) {
            cout << 0 << endl;
            continue;
        }

        sort(vp.begin(), vp.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

        int ans = 0;
        int last_end = -1;

        for (auto &p : vp) {
            if (p.first > last_end) {
                ans++;
                last_end = p.second;
            }
        }

        cout << ans << endl;
    }
}