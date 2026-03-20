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

        vector<vector<int>> c(n);
        unordered_map<int, int> freq;

        // input + count frequency of bits
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            c[i].resize(k);

            for (int j = 0; j < k; j++) {
                cin >> c[i][j];
                freq[c[i][j]]++;
            }
        }

        bool ok = false;

        for (int i = 0; i < n; i++) {
            bool removable = true;

            for (int bit : c[i]) {
                if (freq[bit] == 1) {
                    removable = false;
                    break;
                }
            }

            if (removable) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }

    return 0;
}