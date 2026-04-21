#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<pair<pair<int,int>, int>> vp(n);
        for (int i = 0; i < n; i++) {
            cin >> vp[i].first.first >> vp[i].first.second;
            vp[i].second = i;
        }

        sort(vp.begin(), vp.end());

        int mx = vp[0].first.second;
        int cut = -1;

        for (int i = 1; i < n; i++) {
            if (vp[i].first.first > mx) {
                cut = i;
                break;
            }
            mx = max(mx, vp[i].first.second);
        }

        if (cut == -1) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> ans(n);
        for (int i = 0; i < cut; i++) ans[vp[i].second] = 1;
        for (int i = cut; i < n; i++) ans[vp[i].second] = 2;

        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}