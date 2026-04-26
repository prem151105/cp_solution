#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<int> cnt(10, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x % 10]++;
        }

        bool found = false;

        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= 9; k++) {
                    int need_i = 1;
                    int need_j = 1;
                    int need_k = 1;

                    if (i == j && j == k) {
                        if (cnt[i] < 3) continue;
                    }
                    else if (i == j) {
                        if (cnt[i] < 2 || cnt[k] < 1) continue;
                    }
                    else if (j == k) {
                        if (cnt[j] < 2 || cnt[i] < 1) continue;
                    }
                    else if (i == k) {
                        if (cnt[i] < 2 || cnt[j] < 1) continue;
                    }
                    else {
                        if (cnt[i] < 1 || cnt[j] < 1 || cnt[k] < 1) continue;
                    }

                    if ((i + j + k) % 10 == 3) {
                        found = true;
                    }
                }
            }
        }

        cout << (found ? "YES\n" : "NO\n");
    }

    return 0;
}